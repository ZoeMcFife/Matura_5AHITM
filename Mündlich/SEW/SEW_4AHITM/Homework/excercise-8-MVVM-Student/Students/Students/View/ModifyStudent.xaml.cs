using Students.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Students.View
{
    /// <summary>
    /// Interaction logic for ModifyStudent.xaml
    /// </summary>
    public partial class ModifyStudent : UserControl
    {
        public ModifyStudent()
        {
            InitializeComponent();
        }

        private void ChangeClass(object sender, EventArgs e)
        {
            int studentId = -1;

            if (int.TryParse(Student.Id.Text, out studentId))
            {
                StudentModel? s = StudentDatabase.GetStudent(studentId);
                ClassModel? c = SelectedClass.SelectedClassComboBox.SelectedItem as ClassModel;

                if (s!= null && c != null)
                {
                    s.AssignClass(c.ClassId);
                }
            }


        }
    }
}
