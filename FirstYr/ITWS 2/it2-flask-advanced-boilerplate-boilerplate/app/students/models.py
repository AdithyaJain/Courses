from flask_sqlalchemy import SQLAlchemy
from app import db

class Student(db.Model):
	__tablename__ = 'student'
	rollno = db.Column(db.String(100), primary_key=True)
	name = db.Column(db.String(100))

	def __init__(self, rollno, name):
		self.rollno = rollno
		self.name = name

	def __repr__(self):
		return "Student { name: %r, rollno: %r }"%(self.rollno, self.name)