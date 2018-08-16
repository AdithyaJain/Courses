from api import app, db
from flask_cors import CORS
CORS(app)

if __name__ == '__main__':
	db.create_all()
	app.run(host='0.0.0.0', port=5000, debug=True)
