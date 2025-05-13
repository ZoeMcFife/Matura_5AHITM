using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using download_manager.Model;

namespace download_manager.ViewModel
{
    internal class DownloadViewModel
    {
        public ObservableCollection<Download> Downloads { get; set; }

        public DownloadViewModel()
        {
            Downloads = new ObservableCollection<Download>();

            Download.DownloadStarted += OnDownloadStart;          
        }

        private async void OnDownloadStart(object? sender, DownloadEventArgs e)
        {
            Download newDownload = new Download(e.URL);

            Downloads.Add(newDownload);

            await newDownload.StartDownload();
        }

    }
}
