using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Wpf.Ui;

namespace UIDesign.VIewModel
{
    public partial class DBManagerVM : ObservableObject
    {
        private readonly INavigationService _navigationService;
        public DBManagerVM(INavigationService navigationService)
        {
            _navigationService = navigationService;
        }

        private int number;
        public int Number
        {
            get => number;
            set => SetProperty(ref number, value); // 使用 SetProperty 方法来更新属性并触发通知
        }

        private double price;
        public double Price
        {
            get => price;
            set => SetProperty(ref price, value);
        }
    }
}
