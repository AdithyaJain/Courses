//MAIN/

function addNewStudent(roll, name, year)
{
    function isName(Name)
    {
        var non_alphabet_pattern = new RegExp('[^a-zA-Z. ]+');
        var response = non_alphabet_pattern.exec(Name);
        if (typeof Name === "string" && response === null) return true;
        else { alert("Name should contain only alphabets and spaces"); return false;}
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
    if(isName(name) && isRoll(roll) && isYear(year))
    {       
    $.ajax({
            url: 'http://0.0.0.0:5000/addStudent',
            method: 'POST',
            data: {
                roll: roll,
                name: name,
                year: year,
            },
            success: function(response){alert(response);},
            error: function(response){alert(response);},
        });
    }
}

function addNewStudentOnClick()
{
    roll = $('#addNewStudent_roll').val(), name = $('#addNewStudent_name').val(), year = $('#addNewStudent_year').val();
    addNewStudent(roll, name, year);
    viewAllStudents();
}

function addNewCourse(id, name)
{
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
        else { alert("Course Name should contain only alphabets and spaces"); return false;}
    }
    if(isId(id) && isName(name))
    {
        $.ajax({
            url: 'http://0.0.0.0:5000/addCourse',
            method: 'POST',
            data:{
                id: id,
                name: name,
            },
            success: function(response){alert(response);},
            error: function(response){alert(response);}
        });
    }
}

function addNewCourseOnclick()
{
    var id = $('#addNewCourse_id').val(), name = $('#addNewCourse_name').val();
    addNewCourse(id, name);
    viewAllCourses();
}

function viewAllStudents()
{
    $.ajax({
        url: 'http://0.0.0.0:5000/students',
        method: 'GET',
        success: function(response)
        {
            function addOptToSelect(hashidstring, value)
            {       
                $selectopt = '';
                $selectopt += '<option value="'+value+'" >'+value+'</option>'
                $(hashidstring).html($selectopt);       
            }
            $tablerow = '';
            $addStudentToCourse = '';
            $dropStudentFromCourse = '';
            $removeStudent = '';
            $addCourseToStudent = '';
            for(var i in response.students)
            {
                var roll = response.students[i].roll, name = response.students[i].name, year = response.students[i].year;
                $tablerow += '<tr id="'+roll+'"><td>'+roll+'</td><td>'+name+'</td><td>'+year+'</td></tr>';
                $addStudentToCourse += '<option value="'+roll+'" >'+roll+'</option>';
                $dropStudentFromCourse += '<option value="'+roll+'" >'+roll+'</option>';
                $removeStudent += '<option value="'+roll+'" >'+roll+'</option>';
                $addCourseToStudent += '<option value="'+roll+'" >'+roll+'</option>';
            }
            $("#allStudentsTable").html($tablerow);
            $('#addStudentToCourse_student').html($addStudentToCourse);
            $('#dropStudentFromCourse_student').html($dropStudentFromCourse);
            $('#removeStudent').html($removeStudent);
            $('#coursesTakenByStudent').html($addCourseToStudent);
        },
        error: function(response){ alert(response);},
    });
}

function viewAllCourses()
{
    $.ajax({
        url: 'http://0.0.0.0:5000/courses',
        method: 'GET',
        success: function(response)
        {
            $tablerow = '';
            $addStudentToCourse = '';
            $dropStudentFromCourse = '';
            $removeCourse = '';
            $studentAppliedForCourse = '';
            for(var i in response.courses)
            {
                var id = response.courses[i].id, name = response.courses[i].name;
                $tablerow += '<tr id="'+id+'"><td>'+id+'</td><td>'+name+'</td></tr>';
                $addStudentToCourse += '<option value="'+id+'" >'+id+'</option>';
                $dropStudentFromCourse += '<option value="'+id+'" >'+id+'</option>';
                $removeCourse += '<option value="'+id+'" >'+id+'</option>';
                $studentAppliedForCourse += '<option value="'+id+'" >'+id+'</option>';
            }
            $("#allCoursesTable").html($tablerow);
            $('#addStudentToCourse_course').html($addStudentToCourse);
            $('#dropStudentFromCourse_course').html($dropStudentFromCourse);
            $('#removeCourse').html($removeCourse);
            $('#studentAppliedForCourse').html($studentAppliedForCourse);
        },
        error: function(response){ alert(response);},
    });
}

function addStudentToCourse(roll, id)
{
    $.ajax({
        url: 'http://0.0.0.0:5000/enroll',
        method: 'POST',
        data:{
            roll: roll,
            id: id,
        },
        success: function(response){ alert(response);},
        error: function(response){ alert(response);},
    });
}

function addStudentToCourseOnClick()
{
    var roll = $('#addStudentToCourse_student').val(), id = $('#addStudentToCourse_course').val();
    addStudentToCourse(roll, id);
}

function dropStudentFromCourse(roll, id)
{
    $.ajax({
        url: 'http://0.0.0.0:5000/drop',
        method: 'POST',
        data:{
            roll: roll,
            id: id,
        },
        success: function(response){ alert(response);},
        error: function(response){ alert(response);},
    });
}

function dropStudentFromCourseOnClick()
{
    var roll = $('#dropStudentFromCourse_student').val(), id = $('#dropStudentFromCourse_course').val();
    dropStudentFromCourse(roll, id);
}

function removeCourse(id)
{
    $.ajax({
        url: 'http://0.0.0.0:5000/deleteCourse',
        method: 'POST',
        data:{
            id: id,
        },
        success: function(response){alert(response);},
        error: function(response){alert(response);},
    });
}

function removeCourseOnClick()
{
    var id = $('#removeCourse').val();
    removeCourse(id);
    viewAllCourses();
}

function removeStudent(roll)
{
    $.ajax({
        url: 'http://0.0.0.0:5000/deleteStudent',
        method: 'POST',
        data:{
            roll: roll,
        },
        success: function(response){alert(response);},
        error: function(response){alert(response);},
    });
}

function removeStudentOnClick()
{
    var roll = $('#removeStudent').val();
    removeStudent(roll);
    viewAllStudents();
}

function viewEnrolled(id)
{
    $.ajax({
        url: 'http://0.0.0.0:5000/studentsEnrolled',
        method: 'GET',
        data:{
            id: id,
        },
        success: function(response)
        {
            ans = '';
            for(var i in response.students)
            {
                ans += '<tr><td>'+response.students[i].roll+'</td><td>'+response.students[i].name+'</td><td>'+response.students[i].year+'</td></tr>'
            }
            $('#studentAppliedForCourseTable').html(ans);
        },
        error: function(response){alert(response);},
    });
}

function viewEnrolledOnClick()
{
    var id = $('#studentAppliedForCourse').val();
    viewEnrolled(id);
}

function viewCoursesTaken(roll)
{
    $.ajax({
        url: 'http://0.0.0.0:5000/coursesTaken',
        method: 'GET',
        data:{
            roll: roll,
        },
        success: function(response)
        {
            ans = '';
            for(var i in response.courses)
            {
                ans += '<tr><td>'+response.courses[i].id+'</td><td>'+response.courses[i].name+'</td><tr>';
            }
            $('#coursesTakenByStudentTable').html(ans);
        },
        error: function(response){alert(response);},
    });
}

function viewCoursesTakenOnClick()
{
    var roll = $('#coursesTakenByStudent').val();
    viewCoursesTaken(roll);
}

$(document).ready(function(){
    viewAllStudents();
    viewAllCourses();
});

module.exports.addNewStudent = addNewStudent;
module.exports.addNewCourse = addNewCourse;
module.exports.viewAllStudents = viewAllStudents;
module.exports.viewAllCourses = viewAllCourses;
module.exports.addStudentToCourse = addStudentToCourse;
module.exports.dropStudentFromCourse = dropStudentFromCourse;
module.exports.removeCourse = removeCourse;
module.exports.removeStudent = removeStudent;
module.exports.viewEnrolled = viewEnrolled;
module.exports.viewCoursesTaken = viewCoursesTaken;