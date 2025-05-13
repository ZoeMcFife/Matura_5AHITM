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
    /// Interaction logic for AddStudent.xaml
    /// </summary>
    public partial class AddStudent : UserControl
    {
        public AddStudent()
        {
            InitializeComponent();
        }

        private void AddNewStudent_Click(object sender, RoutedEventArgs e)
        {
            StudentModel newStudent = new StudentModel(StudentNameTextBox.Text);

            ClassModel? c = SelectedClass.SelectedClassComboBox.SelectedItem as ClassModel;

            if (c != null)
            {
                newStudent.AssignClass(c.ClassId);
            }

            StudentDatabase.AddStudent(newStudent);

            StudentNameTextBox.Clear();
        }
    }
}
