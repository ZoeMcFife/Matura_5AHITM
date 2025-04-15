using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Students.Model
{
    internal class StudentModel : INotifyPropertyChanged
    {
        public int StudentId { get; set; }

        private string? _name;

        public string? Name 
        { 
            get
            {
                return _name;
            }
            set
            {
                _name = value;

                OnPropertyChanged(nameof(Name));
            }
        
        }

        private ClassModel? _assignedClass;

        public ClassModel? AssignedClass 
        { 
            get
            {
                return _assignedClass;
            }
            
            private set
            {
                _assignedClass = value;

                OnPropertyChanged(nameof(AssignedClass));
            }
        }

        private static int _lastId = -1;

        public StudentModel(string name) 
        {
            Name = name;

            _lastId = _lastId + 1;

            StudentId = _lastId;
        }

        public StudentModel(string name, ClassModel assignedClass) : this(name)
        {
            AssignedClass = assignedClass;
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        protected virtual void OnPropertyChanged([CallerMemberName] string? propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }


        public void AssignClass(int ClassId)
        {
            AssignedClass = StudentDatabase.GetClass(ClassId);
        }

        public void ClearClass()
        {
            AssignedClass = null;
        }
    }
}
