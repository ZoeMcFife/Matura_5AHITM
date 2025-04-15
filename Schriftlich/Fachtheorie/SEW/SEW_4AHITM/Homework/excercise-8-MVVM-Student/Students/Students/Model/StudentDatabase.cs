using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

/*
 * This Class acts like a Database. It stores all Students and Classes in a List.  
*/
namespace Students.Model
{
    internal class StudentDatabase
    {
        private static List<StudentModel> _students = new List<StudentModel>();
        private static List<ClassModel> _classes = new List<ClassModel>();

        public static List<StudentModel> Students
        {
            get { return _students; }
        }

        public static List<ClassModel> Classes
        { 
            get { return _classes; }
        }

        static StudentDatabase()
        {
            AddStudent(new StudentModel("Test"));
            AddStudent(new StudentModel("Test1"));
            AddStudent(new StudentModel("Test2"));
            AddStudent(new StudentModel("Test3"));
            AddStudent(new StudentModel("Test4"));
            AddStudent(new StudentModel("Test5"));
            AddClass(new ClassModel("ClassTest1"));
            AddClass(new ClassModel("ClassTest2"));
            AddClass(new ClassModel("ClassTest3"));
            AddClass(new ClassModel("ClassTest4"));
        }

        public static void AddStudent(StudentModel student)
        {
            _students.Add(student);
            OnStudentListChanged();
        }

        public static StudentModel? GetStudent(int id) 
        {
            return _students.Find(s => s.StudentId == id);
        }

        public static void RemoveStudent(int id) 
        {
            StudentModel? student = GetStudent(id);

            if (student != null)
                _students.Remove(student);

            OnStudentListChanged();
        }

        public static void AddClass(ClassModel classModel)
        {
            _classes.Add(classModel);
            OnClassListChanged();
        }

        public static ClassModel? GetClass(int id)
        {
            return _classes.Find(c => c.ClassId == id);
        }

        public static void RemoveClass(int id)
        {
            ClassModel? classModel = _classes.Find(c => c.ClassId == id);

            if (classModel != null)
            {
                foreach(StudentModel s in _students.FindAll(s => s.AssignedClass == classModel))
                {
                    s.ClearClass();
                }

                _classes.Remove(classModel);
            }
            
            OnClassListChanged();
        }

        public static event EventHandler ClassListChanged;

        private static void OnClassListChanged()
        {
            ClassListChanged?.Invoke(null, EventArgs.Empty);
        }

        public static event EventHandler StudentListChanged;

        private static void OnStudentListChanged()
        {
            StudentListChanged?.Invoke(null, EventArgs.Empty);
        }
    }
}
