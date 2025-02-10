using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Threading;

namespace snake
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        DispatcherTimer timer1 = new DispatcherTimer();
        int size = 20;
        int X = 67;
        int Y = 39;
        int x = 0;
        Button btn = new Button();
        Button fenshu = new Button();
        Button close = new Button();
        List<Border> snake = new List<Border>();//通过索引来访问蛇的数目
        Border food = new Border();
        Random p = new Random();
        MediaPlayer beijing = new MediaPlayer();
        public MainWindow()
        {
            InitializeComponent();
            buju2.Background = Brushes.DarkOrange;
            buju.Background = new RadialGradientBrush(Colors.White,Colors.Yellow);
            this.WindowStyle = WindowStyle.None;
            this.WindowState = WindowState.Maximized;

            this.KeyDown += MainWindow_KeyDown;
            timer1.Interval = TimeSpan.FromSeconds(0.05);
            timer1.Tick += Timer1_Tick;


        }

        private void button()
        {
            btn.Background = new RadialGradientBrush(Colors.Azure, Colors.Red);//设置开始暂停控制按钮的背景渐变色
            btn.Content = "开始游戏";//设置按钮的标题
            btn.Width = 100;//设置按钮的宽度
            btn.Height = 50;//设置按钮的高度
            btn.Click += Btn_Click;//添加按钮点击事件
            Canvas.SetTop(btn, 10);
            Canvas.SetLeft(btn, 1400);
            buju2.Children.Add(btn);//向容器中增加按钮
            fenshu.Content = "得分:" + x;
            fenshu.Width = 100;
            fenshu.Height = 50;
            fenshu.Background = new RadialGradientBrush(Colors.White, Colors.Tomato);
            Canvas.SetLeft(fenshu, 1400);
            Canvas.SetTop(fenshu, 100);
            buju2.Children.Add(fenshu);
            close.Content = "关闭游戏";
            close.Width = 100;
            close.Height = 50;
            close.Background = new RadialGradientBrush(Colors.Red, Colors.Green);
            Canvas.SetLeft(close, 1400);
            Canvas.SetTop(close, 200);
            close.Click += Close_Click;
            buju2.Children.Add(close);
        }

        private void Close_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void Btn_Click(object sender, RoutedEventArgs e)
        {
            beijing.Open(new Uri("../../music/泠鸢yousa - 勾指起誓.mp3", UriKind.Relative));
            beijing.MediaEnded += Beijing_MediaEnded;
            if (btn.Content.ToString() == "开始游戏")
            {
                timer1.Start();
                beijing.Play();
                btn.Content = "暂停游戏";
                beijing.Position = new TimeSpan();
            }
            else if (btn.Content.ToString() == "暂停游戏")
            {
                //beijing.NaturalDuration = new Duration();
                timer1.Stop();
                beijing.Pause();
                btn.Content = "开始游戏";
            }
        }

        //设置音乐循环播放
        private void Beijing_MediaEnded(object sender, EventArgs e)
        {
            beijing.Position = new TimeSpan(0);
            beijing.Play();
        }

        private void Timer1_Tick(object? sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

        private void MainWindow_KeyDown(object sender, KeyEventArgs e)
        {
            throw new NotImplementedException();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            buju.Width = this.Width - 200;
            buju.Height = this.Height;
        }

        private void SetSnake()
        {
            for(int i = 0;i <5 ;i++)
            {
                Border she = new Border();
                she.Width = she.Height = size;
                if (i == 0)
                {
                    she.Background = new RadialGradientBrush(Colors.White, Colors.Orange);
                }
                else
                {
                    she.Background = new RadialGradientBrush(Colors.SkyBlue,Colors.Purple);
                }

                Canvas.SetLeft(she,X/2*size - i * size);
                Canvas.SetTop(she,Y/2*size);
                she.Tag = "Right";
                she.CornerRadius = new CornerRadius(size / 2);
                buju.Children.Add(she);
                snake.Add(she);
            }
        }

        private void SetFood()
        {
            food.Width = food.Height = size;
            food.CornerRadius = new CornerRadius(size / 2);

            Canvas.SetLeft(food,p.Next(X) * size);
            Canvas.SetTop(food,p.Next(Y) * size);
            food.Background = new RadialGradientBrush(Colors.Yellow, Colors.Green);//设置渐变色
            buju.Children.Add(food);//增加食物控件到容器中
        }

        private void Addshe()
        {
            Border zshe = new Border();
            zshe.Width = zshe.Height = size;//定义宽高
            zshe.Background = new RadialGradientBrush(Colors.Silver, Colors.Red);
            //设置蛇的位置
            Canvas.SetLeft(zshe, Canvas.GetLeft(snake[snake.Count - 1]));//设置在最后一个位置
            Canvas.SetTop(zshe, Canvas.GetTop(snake[snake.Count - 1]));
            zshe.Tag = " ";
            zshe.CornerRadius = new CornerRadius(size / 2);//进行border画圆
            buju.Children.Add(zshe);//添加控件
            snake.Add(zshe);//将蛇放进这个数组列表中进行查找
        }
    }
}