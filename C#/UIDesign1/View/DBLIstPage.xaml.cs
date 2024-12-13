using Wpf.Ui.Controls;

namespace UIDesign.View
{
    /// <summary>
    /// Interaction logic for UserControl1.xaml
    /// </summary>
    public partial class DBListPage : INavigableView<VIewModel.DBListVM>
    {
        public VIewModel.DBListVM ViewModel { get; }

        public DBListPage()
        {
            ViewModel = new VIewModel.DBListVM(navigationService: null);
            InitializeComponent();
            DataContext = ViewModel;
        }

        public DBListPage(VIewModel.DBListVM viewModel)
        {
            ViewModel = viewModel;
            DataContext = this;

            InitializeComponent();
        }
    }
}
