using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Server
{
    public static void Main(string[] args)
    {
        StartServer();
    }

    public static void StartServer()
    {
        byte[] bytes = new Byte[1024];

        // 监听IP和端口
        IPAddress ipAddress = IPAddress.Parse("127.0.0.1");
        IPEndPoint localEndPoint = new IPEndPoint(ipAddress, 11000);

        // 创建 TCP/IP Socket 
        Socket listener = new Socket(ipAddress.AddressFamily,
            SocketType.Stream, ProtocolType.Tcp);

        try
        {
            // 绑定 IP 地址和端口
            listener.Bind(localEndPoint);

            // 开始监听传入的连接请求
            listener.Listen(10);

            Console.WriteLine("等待连接...");
            Socket handler = listener.Accept();

            // 连接成功后接收数据
            string data = null;

            while (true)
            {
                bytes = new byte[1024];
                int bytesRec = handler.Receive(bytes);
                data += Encoding.UTF8.GetString(bytes, 0, bytesRec);
                if (data.IndexOf("<EOF>") > -1)
                {
                    break;
                }
            }

            Console.WriteLine("从客户端收到的消息: {0}", data);

            // 向客户端发送响应消息
            byte[] msg = Encoding.UTF8.GetBytes("服务器已接收到您的消息。");
            handler.Send(msg);

            handler.Shutdown(SocketShutdown.Both);
            handler.Close();
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }

        Console.WriteLine("\n按任意键继续...");
        Console.ReadKey();
    }
}
