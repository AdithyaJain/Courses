from flask import Blueprint, request, render_template, \
                  flash, g, session, redirect, url_for
from app import db
from app.students.models import Student

mod_students = Blueprint('students', __name__, url_prefix='/students')

@mod_students.route('/', methods=['GET'])
def get_all_students():
	# set students to the appropriate value
	students = Student.query.all()
	return render_template('students/index.html', students=students)

@mod_students.route('/search', methods=['GET'])
def search_students():
	q = request.args.get('q')
	students = Student.query.filter(Student.name.like('%'+q+'%')).all()
	return render_template('students/index.html', students=students)

@mod_students.route('/<rollno>', methods=['GET'])
def get_student(rollno):
	# set student to the appropriate value
	student = Student.query.filter_by(rollno=rollno)
	return render_template('students/index.html', students=student)

@mod_students.route('/create', methods=['GET','POST'])
def create_student():
	if request.method == 'POST':
		if not request.form['rollno'] or not request.form['name']:
			flash('Please enter all fields','error')
		else:
			student = Student(request.form['rollno'],request.form['name'])
			db.session.add(student)
			db.session.commit()
			return redirect(url_for('students.get_all_students'))
	return render_template('students/addNew.html')

@mod_students.route('/<rollno>/delete',methods=['GET'])
def delete_student(rollno):
	Student.query.filter_by(rollno=rollno).delete()
	db.session.commit()
	return redirect(url_for('students.get_all_students'))
	return render_template('students/index.html')