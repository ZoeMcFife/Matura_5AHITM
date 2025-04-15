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
using Students.Model;

namespace Students.View
{
    /// <summary>
    /// Interaction logic for AddClass.xaml
    /// </summary>
    public partial class AddClass : UserControl
    {
        public AddClass()
        {
            InitializeComponent();
        }

        private void AddNewClass_Click(object sender, RoutedEventArgs e)
        {
            ClassModel newClass = new ClassModel(ClassNameTextBox.Text);

            StudentDatabase.AddClass(newClass);

            ClassNameTextBox.Clear();
        }
    }
}
