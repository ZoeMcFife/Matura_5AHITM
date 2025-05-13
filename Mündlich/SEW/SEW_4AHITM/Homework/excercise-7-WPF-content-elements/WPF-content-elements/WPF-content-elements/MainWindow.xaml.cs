using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WPF_content_elements
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private bool _IsFilled { get; set; } = false;


        private static Random _random = new Random();

        public MainWindow()
        {
            InitializeComponent();
        }


        private void FillListBox_Click(object sender, RoutedEventArgs e)
        {
            if (_IsFilled) return; 

            for (int i = 0; i < 7; i++)
            {
                listBox.Items.Add(GenerateRandomString(10));
            }

            _IsFilled = true;
        }

        private void ClearListBox_Click(object sender, RoutedEventArgs e)
        {
            listBox.Items.Clear();
            _IsFilled = false;
        }

        private string GenerateRandomString(int length)
        {
            const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
            StringBuilder result = new StringBuilder(length);

            for (int i = 0; i < length; i++)
            {
                result.Append(chars[_random.Next(chars.Length)]);
            }

            return result.ToString();
        }

        private void FillTree_Click(object sender, RoutedEventArgs e)
        {
            for (int i = 0; i < 5; i++) 
            {
                TreeViewItem item = GenerateRandomTreeViewItem();

                for (int j = 0; j < _random.Next(0, 5); j++)
                {
                    item.Items.Add(GenerateRandomTreeViewItem());
                }

                tree.Items.Add(item);
            }
        }

        private TreeViewItem GenerateRandomTreeViewItem()
        {
            TreeViewItem item = new TreeViewItem();
            item.Header = GenerateRandomString(10);

            return item;
        }

        private void ClearTree_Click(object sender, RoutedEventArgs e)
        {
            tree.Items.Clear();
        }

        private void PanelClick(object sender, MouseButtonEventArgs e)
        {
            clickLabel.Content = clickLabel.Content + " click";
        }

        private void OpenPopup(object sender, RoutedEventArgs e)
        {
            if (myPopup.IsOpen == true)
                myPopup.IsOpen = false;
            else
                myPopup.IsOpen = true;
        }
    }
}
