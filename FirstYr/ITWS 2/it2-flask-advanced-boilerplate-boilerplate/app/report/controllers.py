from flask import Blueprint, request, render_template, \
                  flash, g, session, redirect, url_for
from app import db
from app.report.models import GradeEntry

mod_report = Blueprint('report', __name__, url_prefix='/report')

@mod_report.route('/student/<rollno>', methods=['GET'])
def get_student_grades(rollno):
    # set courses to the appropriate value

    return render_template('report/courses_for_student.html', report=grades)

@mod_report.route('/course/<code>', methods=['GET'])
def get_course(code):
    # set courses to the appropriate value
    
    return render_template('report/students_for_course.html', report=grades)
