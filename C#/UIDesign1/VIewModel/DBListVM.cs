using CommunityToolkit.Mvvm.ComponentModel;
using UIDesign.Model;
using UIDesign.utils;
using Wpf.Ui;

namespace UIDesign.VIewModel
{
    public class DBListVM : ObservableObject
    {
        private readonly INavigationService _navigationService;
        
        public DBListVM(INavigationService navigationService)
        {
            _navigationService = navigationService;
            ReportInfo = new RecordListInfo();
            InitData();
        }

        private void InitData()
        {
        }

        private RecordListInfo reportInfo;
        public RecordListInfo ReportInfo
        {
            get => reportInfo;
            set => SetProperty(ref reportInfo, value);
            
                
        }
    }
}
