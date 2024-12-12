using System.Data.Common;
using Microsoft.Data.Sqlite;
using System.Data.SQLite.EF6;
using System.IO;
using SQLiteConnection = System.Data.SQLite.SQLiteConnection;
using System.Data.SQLite;
namespace UIDesign.Helper
{
    /// <summary>
    /// 数据库管理类
    /// </summary>
    public class SQLiteHelper
    {
        private static readonly string _path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Database");

        public static void InitializeDatabase()
        {
            string _databaseFilePath = Path.Combine(_path, "myDB.db");

            if (!Directory.Exists(_path))
            {
                Directory.CreateDirectory(_path);
            }

            if (!File.Exists(_databaseFilePath))
            {
                SQLiteConnection.CreateFile(_databaseFilePath);

                // 创建表
                using (var connection = new SQLiteConnection($"Data Source={_databaseFilePath};Version=3;"))
                {
                    connection.Open();

                    string createTableQuery = @"
            CREATE TABLE IF NOT EXISTS Users (
                Id INTEGER PRIMARY KEY AUTOINCREMENT,
                Number TEXT NOT NULL,
                Price TEXT NOT NULL
            );";

                    using (var command = new SQLiteCommand(createTableQuery, connection))
                    {
                        command.ExecuteNonQuery();
                        Console.WriteLine("Table 'Users' created.");
                    }
                }

            }
            else
            {
                Console.WriteLine("Database already exists.");
            }
        }

        /// <summary>
        /// 数据库连接方法
        /// </summary>
        /// <returns></returns>
        public static DbConnection GetDbConnection()
        {
            string _databaseFilePath = Path.Combine(_path, "myDB.db");
            DbConnection dbConnection = SQLiteProviderFactory.Instance.CreateConnection();
            string targetFolder = $"{System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase}Database";
            if (!System.IO.Directory.Exists(_path))
            {
                System.IO.Directory.CreateDirectory(targetFolder);
            }
            dbConnection.ConnectionString = _databaseFilePath;
            return dbConnection;
        }
    }
}
