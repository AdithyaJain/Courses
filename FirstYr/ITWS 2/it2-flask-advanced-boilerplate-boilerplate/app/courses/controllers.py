from flask import Blueprint, request, render_template, \
                  flash, g, session, redirect, url_for
from app import db
from app.courses.models import Course

mod_courses = Blueprint('courses', __name__, url_prefix='/courses')

@mod_courses.route('/', methods=['GET'])
def get_all_courses():
	courses = Course.query.all()
	return render_template('courses/index.html', courses=courses)

@mod_courses.route('/search', methods=['GET'])
def search_courses():
	q = request.args.get('q')
	courses = Course.query.filter(Course.name.like('%'+q+'%')).all()
	return render_template('courses/index.html', courses=courses)

@mod_courses.route('/<code>', methods=['GET'])
def get_course(code):
	course = Course.query.filter_by(code=code)
	return render_template('courses/index.html', courses=course)

@mod_courses.route('/create',methods=['POST','GET'])
def create_course():
	if request.method == 'POST':
		if not request.form['code'] or not request.form['name'] or not request.form['description']:
			flash('Please enter all fields','error')
		else:
			course = Course(request.form['code'], request.form['name'], request.form['description'])
			db.session.add(course)
			db.session.commit()
			return redirect(url_for('courses.get_all_courses'))
	return render_template('courses/addNew.html')

@mod_courses.route('/<code>/delete',methods=['GET'])
def delete_course(code):
	Course.query.filter_by(code=code).delete()
	db.session.commit()
	return redirect(url_for('courses.get_all_courses'))
	return render_template('courses/index.html')