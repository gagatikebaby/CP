using Wpf.Ui.Controls;


namespace UIDesign.View
{
    /// <summary>
    /// Interaction logic for UIDataBaseManager.xaml
    /// </summary>
    public partial class DBManagerPage : INavigableView<VIewModel.DBManagerVM>
    {
        public VIewModel.DBManagerVM ViewModel { get; }
        public DBManagerPage(VIewModel.DBManagerVM viewModel)
        {
            ViewModel = viewModel;
            DataContext = this;

            InitializeComponent();
        }
    }
}
