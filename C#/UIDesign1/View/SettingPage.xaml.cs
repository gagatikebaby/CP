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
using UIDesign.VIewModel;
using Wpf.Ui.Appearance;
using Wpf.Ui.Controls;

namespace UIDesign.View
{
    /// <summary>
    /// Interaction logic for SettingPage.xaml
    /// </summary>
    public partial class SettingPage : INavigableView<SettingVM>
    {
        public SettingVM ViewModel { get; }
        //public SettingPage()
        //{
        //    InitializeComponent();
        //}

        public SettingPage()
        {
            ViewModel = new SettingVM(navigationService: null);
            DataContext = this;

            InitializeComponent();
        }

        public SettingPage(SettingVM viewModel)
        {
            ViewModel = viewModel;
            DataContext = this;

            InitializeComponent();
        }

        private void ComboBox_FocusableChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            //ViewModel.OnCurrentApplicationThemeChanged(0, (ApplicationTheme)Cmb_ThemeChange.SelectedIndex);
        }
    }
}
