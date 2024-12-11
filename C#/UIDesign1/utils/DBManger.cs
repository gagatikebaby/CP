using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UIDesign.utils
{
    public class DBManger
    {
        private string _path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Database");
        //private string 
        //string folderPath = Path.GetDirectoryName(_databaseFilePath);
        public void InitializeDatabase()
        {
            string _databaseFilePath = Path.Combine(_path,"myDB.db");

            if (!Directory.Exists(_path))
            {
                Directory.CreateDirectory(_path);
            }

            if(!File.Exists(_databaseFilePath))
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
                    //connection.ChangePassword("123");
                }

            }
            else
            {
                Console.WriteLine("Database already exists.");
            }
        }
    }
}
