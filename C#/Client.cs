using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Client
{
    public static void Main(string[] args)
    {
        StartClient();
    }

    public static void StartClient()
    {
        byte[] bytes = new byte[1024];

        try
        {
            // 连接到远程端点
            IPHostEntry ipHostInfo = Dns.GetHostEntry("localhost");
            IPAddress ipAddress = ipHostInfo.AddressList[1];
            IPEndPoint remoteEP = new IPEndPoint(ipAddress, 11000);

            Socket sender = new Socket(ipAddress.AddressFamily,
                SocketType.Stream, ProtocolType.Tcp);

            try
            {
                sender.Connect(remoteEP);

                Console.WriteLine("Socket 连接到 {0}",
                    sender.RemoteEndPoint.ToString());

                // 发送数据到服务器
                string msg = "这是来自客户端的消息<EOF>";
                //byte[] msgBytes = Encoding.ASCII.GetBytes(msg);
                byte[] msgBytes = Encoding.UTF8.GetBytes(msg);
                int bytesSent = sender.Send(msgBytes);

                // 接收服务器响应
                int bytesRec = sender.Receive(bytes);
                Console.WriteLine("从服务器收到的消息: {0}",
                    Encoding.UTF8.GetString(bytes, 0, bytesRec));

                // 关闭连接
                sender.Shutdown(SocketShutdown.Both);
                sender.Close();
            }
            catch (ArgumentNullException ane)
            {
                Console.WriteLine("ArgumentNullException : {0}", ane.ToString());
            }
            catch (SocketException se)
            {
                Console.WriteLine("SocketException : {0}", se.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine("Unexpected exception : {0}", e.ToString());
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }

        Console.WriteLine("\n按任意键继续...");
        Console.ReadKey();
    }
}
