from flask_sqlalchemy import SQLAlchemy
from app import db


class GradeEntry(db.Model):
	__tablename__ = 'grade_entry'
	assignments = db.Column(Float)
	labs = db.Column(Float)
	mids = db.Column(Float)
	end_sem = db.Column(Float)
	student_rollno = 
	course_code = 

	def __init__(self, student, course):
		self.assignments = 0.0
		self.labs = 0.0
		self.mids = 0.0
		self.end_sem = 0.0