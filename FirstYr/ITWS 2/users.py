from flask import *
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:////tmp/test.db'
db = SQLAlchemy(app)

class User(db.Model):
        id = db.Column(db.Integer, primary_key=True)
        username = db.Column(db.String(80), unique=True)
        email = db.Column(db.String(120), unique=True)

        def __init__(self, username, email):
                self.username = username
                self.email = email

        def __repr__(self):
                return '<User %r>' % self.username

@app.route("/addUser", methods = ['POST'])
def add_user():
        username = request.form['username']
        email = request.form['email']
        user = User(username, email)
        try:    
                db.session.add(user)
                db.session.commit()
                return jsonify(
                        status= 'true'
                )
        except:
                return jsonify(
                        status= 'false'
                )

@app.route("/users", methods = ['GET'])
def get_users():
        users = User.query.all()
        all_users = []
        for user in users:
                all_users.append({'email': user.email, 'username':user.username})
        return jsonify({'users': all_users})

@app.route("/deleteUser", methods = ['POST'])
def delete_user():
        username = request.form["username"]
        try:    
                user = User.query.filter_by(username= username).first()
                db.session.delete(user) 
                db.session.commit()
                return jsonify(
                        status= 'true'
                )
        except:
                return jsonify(
                        status= 'false'
                )
db.create_all()

if __name__ == "__main__":
        app.run()