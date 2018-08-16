# The Data Model

* Student = (**rollno**, name)
* Course = (**code**, name, description)
* GradeEntry = (*student_rollno*, *course_code*, assignments, labs, mids, end_sem)

**bold** indicates primary key, *italic* foreign key. Also:
* *student_rollno* -> **rollno**
* *course_code* -> **code**

Think of the student module as some student profile module, and the course
module as a course info page module and the report as another module which is
built by associating student and courses.


# Routes Required

```
/students/ - GET(read)
/students/<rollno> - GET(read), POST(update)
/students/create - GET(form), POST(create)
/students/<rollno>/delete - POST(delete)

/courses/ - GET(read)
/courses/<code> - GET(read), POST(update)
/courses/create - GET(form), POST(create)
/courses/<code>/delete - POST(delete)

-- Search.
/students/search - GET
/courses/search - GET

/report/student/<rollno> - GET(read)
/report/course/<code> - GET(read)
/report/entry/<rollno>/<code> - GET(read)
```
