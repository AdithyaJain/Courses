from flask import *
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:////tmp/test.db'
db = SQLAlchemy(app)

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(80))
    email = db.Column(db.String(120))

    def __init__(self, name, email):
        self.name = name
        self.email = email

    def __repr__(self):
        return '<User %r>' % self.name

@app.route("/addUser")
def add_user():
  print(request.args)
  name = request.args.get("name")
  email = request.args.get("email")

  user = User(name, email)
  db.session.add(user)
  try:
    db.session.commit()
  except:
    return "Duplicates not allowed"
  return "Successfully added"

@app.route("/users")
def get_users():
  query = request.args.get("query")
  all_users = User.query.filter(User.name.like("%" + query + "%")).all()
  for user in all_users:
    print(user.name, user.email)
  return redirect("/new_route")
  return "All users printed"

@app.route("/new_route")
def newroute():
  return "You were redirected to this page"

@app.route("/template_example")
def template():
  return render_template("example.html, "names=["Raj", "Harshit", "Mohit"])

db.create_all()

if __name__ == "__main__":
  app.run(debug=True)