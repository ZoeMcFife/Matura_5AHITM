using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Net;
using System.Runtime.CompilerServices;
using System.Security.Policy;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace download_manager.Model
{
    internal class Download : INotifyPropertyChanged
    {
        private DownloadState _state = DownloadState.NotStarted;

        public DownloadState State
        {
            get
            {
                return _state;
            }

            set 
            { 
                _state = value; 
                OnPropertyChanged(nameof(State)); 
            } 
        }

        private int _downloadProgress;

        public int DownloadProgress
        {
            get
            {
                return _downloadProgress;
            }
            set
            {
                _downloadProgress = value;
                OnPropertyChanged(nameof(DownloadProgress));
            }
        }

        public string URL { get; set; } = string.Empty;

        public static event EventHandler<DownloadEventArgs>? DownloadStarted;

        public Download(string url)
        {
            URL = url;
        }

        public static void StartDownloadEvent(string URL)
        {
            DownloadStarted?.Invoke(null, new DownloadEventArgs(URL));
        }

        public async Task StartDownload()
        {
            State = DownloadState.Started;

            await Task.Run(() =>
            {
                string filename = ExtractFileNameFromURL(URL);
                string path = "C:\\users\\" + Environment.UserName + "\\Downloads\\DOWNLOAD_MANAGER\\" + filename;

                WebClient webClient = new();

                webClient.DownloadProgressChanged += (object sender, DownloadProgressChangedEventArgs e) => { DownloadProgress = e.ProgressPercentage; };
                webClient.DownloadFileCompleted += (object? sender, AsyncCompletedEventArgs e) => { State = DownloadState.Success; };

                try 
                {
                    webClient.DownloadFileAsync(new Uri(URL), path);
                }
                catch (Exception ex) 
                {
                    State = DownloadState.Failure;
                }
            });
        }

        private string ExtractFileNameFromURL(string url)
        {
            try
            {
                Uri uri = new Uri(url);

                string lastSegment = uri.Segments[uri.Segments.Length - 1];

                string fileName = Uri.UnescapeDataString(lastSegment);

                return fileName;
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        protected virtual void OnPropertyChanged([CallerMemberName] string? propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
