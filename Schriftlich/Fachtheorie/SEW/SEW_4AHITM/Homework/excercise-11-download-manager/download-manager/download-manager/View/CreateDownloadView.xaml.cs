using download_manager.Model;
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
using download_manager.ViewModel;

namespace download_manager.View
{
    /// <summary>
    /// Interaction logic for CreateDownloadView.xaml
    /// </summary>
    public partial class CreateDownloadView : UserControl
    {


        public CreateDownloadView()
        {
            InitializeComponent();
        }

        private void StartDownloadButton_ClickedAsync(object sender, RoutedEventArgs e)
        {
            Download.StartDownloadEvent(UrlTextBlock.Text);

            UrlTextBlock.Clear();
        }
    }
}
