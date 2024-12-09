using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UIDesign.utils
{
    public class DBOperation
    {
        
        public static void InsertUser(string username, string password)
        {
            string _path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Database");
            string _databaseFilePath = Path.Combine(_path, "myDB.db");
            using (var connection = new SQLiteConnection($"Data Source={_databaseFilePath};Version=3;"))
            {
                connection.Open();

                string insertQuery = "INSERT INTO Users (Username, Password) VALUES (@username, @password);";

                using (var command = new SQLiteCommand(insertQuery, connection))
                {
                    command.Parameters.AddWithValue("@username", username);
                    command.Parameters.AddWithValue("@password", password);

                    command.ExecuteNonQuery();
                    Console.WriteLine("User inserted.");
                }
            }
        }
    }
}
