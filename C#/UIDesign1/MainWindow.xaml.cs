using System.Windows.Input;
using UIDesign.utils;
using Wpf.Ui.Controls;
namespace UIDesign
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : FluentWindow
    {
        public MainWindow()
        {
            InitializeComponent(); // 必须调用此方法来初始化XAML定义的UI组件
        }

        private void FluentWindow_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            this.DragMove();
        }
    }
}