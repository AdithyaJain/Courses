
//STUDENT
function makeStudent(r, nm, yr)
{
        var student = {};
        var roll = r;
        var name = nm;
        var year = yr;
        var courses = [];
        
        function isName(Name)
        {
            var non_alphabet_pattern = new RegExp('[^a-zA-Z. ]+');
            var response = non_alphabet_pattern.exec(Name);
            if (typeof Name === "string" && response === null) return true;
            else
                { alert("Name should contain only alphabets and spaces"); return false;}
        }
        function isRoll(Roll)
        {
                if(parseInt(Roll) >= 20110000 && parseInt(Roll) <= 20169999) return true;
                else { alert("Roll should be 2011XXXX - 2016XXXX"); return false;}
        }
        function isYear(Year)
        {
                if(Year.length === 3 && Year.charAt(0) === 'U' && Year.charAt(1) === 'G' && Year.charAt(2) >= '1' && Year.charAt(2) <= '6') return true;
                else { alert("Year should be UGx where x = {1-6}"); return false;}
        }
        function isId(id)
        {
        if(id.length === 6)
        {
        var flag = true;
        for(i=0; i<6; i++)
                {
                        if(i<=2 && (id.charAt(i) < 'A' || id.charAt(i) > 'Z')){ flag = false; break;}
                        if(i>2 && (id.charAt(i) <'0' || id.charAt(i) > '9')){ flag = false; break;}
                }
        }
        if(flag) return true;
        else{ alert("Course Id should be YYYXXX Y => [A-Z], X => [0-9]"); return false;}
        }       
        if(isRoll(roll) && isName(name) && isYear(year))
        {
                //student.name = name, student.roll = roll, student.year = year;
                student.getName = function()
                {
                        return name;
                }
                student.getRoll = function()
                {
                        return roll;
                }
                student.getYear = function()
                {
                        return year;
                }
                student.getCourseIds = function()
                {
                        return courses;
                }

                student.addCourse = function(id)
                {
                        if(isId(id)){ courses.push(id); console.log("Added course to student");}
                        else console.log("Course Id should be YYYXXX Y => [A-Z], X => [0-9]");
                } 

                student.dropCourse = function(id)
                {
                        courses.splice(courses.indexOf(id), 1);
                        console.log("Course dropped from student");
                }

                student.findCourse = function(id)
                {
                        if(courses.indexOf(id) === -1) return false;
                        else return true;
                }
                return student;
        }
        else return undefined;
}

//COURSE
var makeCourse = function(i, nm)
{
  var course = {}
  var id = i;
  var name = nm;
  var students = [];

  function isId(id)
  {
    if(id.length === 6)
    {
      var flag = true;
      for(i=0; i<6; i++)
      {
        if(i<=2 && (id.charAt(i) < 'A' || id.charAt(i) > 'Z')){ flag = false; break;}
        if(i>2 && (id.charAt(i) <'0' || id.charAt(i) > '9')){ flag = false; break;}
      }
    }
    if(flag) return true;
    else{ alert("Course Id should be YYYXXX Y => [A-Z], X => [0-9]"); return false;}
  }
 function isName(Name)
  {
    var non_alphabet_pattern = new RegExp('[^a-zA-Z. ]+');
      var response = non_alphabet_pattern.exec(Name);
      if (typeof Name === "string" && response === null) return true;
      else
          { alert("Course Name should contain only alphabets and spaces"); return false;}
  }
  function isRoll(Roll)
  {
    if(parseInt(Roll) >= 20110000 && parseInt(Roll) <= 20169999) return true;
    else { alert("Roll should be 2011XXXX - 2016XXXX"); return false;}
  }

  if(isId(id) && isName(name))
  {
    //course.name = name, course.id = id, course.students = students;
    course.getName =  function()
    {
      return name;
    }
    course.getId =  function()
    {
      return id;
    }
    course.getStudents =  function()
    {
        return students;
    }

    course.addStudent = function(roll)
    {
        if(isRoll(roll)){ students.push(roll); console.log('Added student to course');}
        else console.log("Incorrect Roll Number Given. Should be 2011XXXX - 2016XXXX");
    }

    course.dropStudent = function(roll)
    {
        students.splice(students.indexOf(roll), 1);
        console.log('Dropped student from course');
    }

    course.findStudent = function(roll)
    {
        if(students.indexOf(roll) === -1) return false;
        else return true;
    }

    return course;
  }
  return undefined;
}



//MAIN
//when adding new students and courses, check whether id is already in the array. DOOOOOOOOOOOOOOOOO LATER
//beautify the page
var allStudents = [];
var allCourses = [];


function addOptToSelect(hashidstring, value)
        {       
                $selectopt = $(hashidstring).html();
                $selectopt += '<option value="'+value+'" >'+value+'</option>'
                $(hashidstring).html($selectopt);       
        }


function addNewStudent()
{
        roll = $('#addNewStudent_roll').val(), name = $('#addNewStudent_name').val(), year = $('#addNewStudent_year').val();
        var newStudent = makeStudent(roll, name, year);
        if(newStudent != undefined)
        {
                var flag = true;
                for(var i in allStudents)
                {
                        if(allStudents[i].getRoll() === roll){ flag = false; break;}
                }
                
                if(flag)
                {
                        allStudents.push(newStudent);
                }
                else console.log('roll no already present');
        }       
        else console.log('Incorrect details of student')
}

function addNewCourse()
{
        id = $('#addNewCourse_id').val(), name = $('#addNewCourse_name').val();
        var newCourse = makeCourse(id, name);
        if(newCourse != undefined)
        {
                var flag = true;
                for(var i in allCourses)
                {
                        if(allCourses[i].getId() === id){ flag = false; break;}
                }

                if(flag) allCourses.push(newCourse);
                else console.log("course id already present");
        }
        else console.log("incorrect course details");
}

function addNewStudentOnClick()
{
        
        roll = $('#addNewStudent_roll').val(), name = $('#addNewStudent_name').val(), year = $('#addNewStudent_year').val();
        var newStudent = makeStudent(roll, name, year);
        if(newStudent != -1)
        {
                var flag = true;
                for(var i in allStudents)
                {
                        if(allStudents[i].getRoll() === roll){ flag = false; break;}
                }
                
                if(flag)
                {
                        allStudents.push(newStudent);

                        $tablerow = $("#allStudentsTable").html();
                        $tablerow += '<tr id="'+roll+'"><td>'+roll+'</td><td>'+name+'</td><td>'+year+'</td></tr>';
                        $("#allStudentsTable").html($tablerow)

                        addOptToSelect("#addStudentToCourse_student", roll);
                        addOptToSelect("#dropStudentFromCourse_student", roll);
                        addOptToSelect('#removeStudent', roll);
                        addOptToSelect('#coursesTakenByStudent', roll);
                        console.log("Ran addNewStudent()");
                }
                else alert('Roll No Already Present');
        }
        else alert('Incorrect Student Details');

        $('#addNewStudent_roll').val(""), $('#addNewStudent_name').val(""), $('#addNewStudent_year').val("");
}


function addNewCourseOnclick()
{
        id = $('#addNewCourse_id').val(), name = $('#addNewCourse_name').val();
        var newCourse = makeCourse(id, name);
        if(newCourse != -1)
        {
                var flag = true;
                for(var i in allCourses)
                {
                        if(allCourses[i].getId() === id){ flag = false; break;}
                }

                if(flag)
                {
                        allCourses.push(newCourse);
                        $tablerow = $("#allCoursesTable").html();
                        $tablerow += '<tr id="'+id+'"><td>'+id+'</td><td>'+name+'</td></tr>';
                        $("#allCoursesTable").html($tablerow)
                        addOptToSelect("#addStudentToCourse_course", id);
                        addOptToSelect("#dropStudentFromCourse_course", id);
                        addOptToSelect('#removeCourse',id);
                        addOptToSelect('#studentAppliedForCourse',id);
                        console.log("Ran addNewCourse()");
                }
                else alert("Id Already Present");
        }
        else alert('Incorrect Course Details');
        $('#addNewCourse_id').val(''), $('#addNewCourse_name').val('');
}

function addStudentToCourse(Student, Course)
{
        if(Student.getCourseIds().indexOf(Course.getId()) == -1)
        {
                Student.addCourse(Course.getId());
                Course.addStudent(Student.getRoll());
        }
        else alert('Student Applied Already!');
}
function addStudentToCourseOnClick()
{
        var studentRoll = $('#addStudentToCourse_student').val();
        var courseId = $('#addStudentToCourse_course').val();

        for(var s in allStudents) if(allStudents[s].getRoll() === studentRoll) break;
        for(var c in allCourses) if(allCourses[c].getId() === courseId) break;
        addStudentToCourse(allStudents[s], allCourses[c]);
        console.log('added'+s+'student to'+c+'course');
        console.log('Added selected student to selected course');
}

function dropStudentFromCourse(Student, Course)
{
        if(Student.getCourseIds().indexOf(Course.getId()) != -1)
        {
                allStudents[allStudents.indexOf(Student)].dropCourse(Course.getId());
                allCourses[allCourses.indexOf(Course)].dropStudent(Student.getRoll());  
        }
        else alert('Student Isnt Applied For Course!');
}
function dropStudentFromCourseOnClick()
{
        var studentRoll = $('#dropStudentFromCourse_student').val();
        var courseId = $('#dropStudentFromCourse_course').val();

        for(var s in allStudents) if(allStudents[s].getRoll() === studentRoll) break;
        for(var c in allCourses) if(allCourses[c].getId() === courseId) break;
        dropStudentFromCourse(allStudents[s], allCourses[c]);
        console.log('Removed selected student from selected course');
}

function removeCourse(Course)
{
        allCourses.splice(allCourses.indexOf(Course), 1);
        for(var i in allStudents)
        {
                allStudents[i].dropCourse(Course.getId());
        }
        $('#'+Course.getId()).remove();
        $('#addStudentToCourse_course option[value='+Course.getId()+']').remove();
        $('#dropStudentFromCourse_course option[value='+Course.getId()+']').remove();
        $('#removeCourse option[value='+Course.getId()+']').remove();
        $('#studentAppliedForCourse option[value='+Course.getId()+']').remove();
}
function removeCourseOnClick()
{
        var courseId = $('#removeCourse').val();
        for(var c in allCourses) if(allCourses[c].getId() === courseId) break;
        removeCourse(allCourses[c]);
        console.log('Removed Course');
}

function removeStudent(Student)
{
        allStudents.splice(allStudents.indexOf(Student), 1);
        for(var i in allCourses)
        {
                allCourses[i].dropStudent(Student.getRoll());
        }
        $('#'+Student.getRoll()).remove();
        $('#addStudentToCourse_student option[value='+Student.getRoll()+']').remove();
        $('#dropStudentFromCourse_student option[value='+Student.getRoll()+']').remove();
        $('#removeStudent option[value='+Student.getRoll()+']').remove();
        $('#coursesTakenByStudent option[value='+Student.getRoll()+']').remove();
}
function removeStudentOnClick()
{
        var studentRoll = $('#removeStudent').val();
        for(var c in allStudents) if(allStudents[c].getRoll() === studentRoll) break;
        removeStudent(allStudents[c]);
        console.log('Removed Student');
}

function viewEnrolled(course)
{
        ans = '';
        for(var i in course.getStudents())
        {
                for(var s in allStudents) if(allStudents[s].getRoll() === course.getStudents()[i]) break;
                ans += '<tr><td>'+allStudents[s].getRoll()+'</td><td>'+allStudents[s].getName()+'</td><td>'+allStudents[s].getYear()+'</td></tr>'
        }
        $('#studentAppliedForCourseTable').html(ans);
}

function viewEnrolledOnClick()
{
        var courseId = $('#studentAppliedForCourse').val();
        for(var i in allCourses) if(allCourses[i].getId() === courseId) break;
        viewEnrolled(allCourses[i]);
        $('#studentAppliedForCourseTable').val(allCourses[i].getId());
        console.log(allCourses[i].getId());
}

function viewCoursesTaken(student)
{
        ans = '';
        for(var i in student.getCourseIds())
        {
                for(var s in allCourses) if(allCourses[s].getId() === student.getCourseIds()[i]) break;
                ans += '<tr><td>'+allCourses[s].getId()+'</td><td>'+allCourses[s].getName()+'</td></tr>'
        }
        $('#coursesTakenByStudentTable').html(ans);
}

function viewCoursesTakenOnClick()
{
        var studentRoll = $('#coursesTakenByStudent').val();
        for(var i in allStudents) if(allStudents[i].getRoll() === studentRoll) break;
        viewCoursesTaken(allStudents[i]);
        $('#coursesTakenByStudentPara').val(allStudents[i].getRoll())
        console.log(allStudents[i].getRoll());
}

module.exports.addNewStudent = addNewStudent;
module.exports.addNewCourse = addNewCourse;
module.exports.addStudentToCourse = addStudentToCourse;
module.exports.dropStudentFromCourse = dropStudentFromCourse
module.exports.removeCourse = RemoveCourse;
module.exports.removeStudent = removeStudent
module.exports.viewEnrolled = viewEnrolled;
module.exports.viewCoursesTaken = viewCoursesTaken;
