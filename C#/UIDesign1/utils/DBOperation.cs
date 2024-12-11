using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.IO;

namespace UIDesign.utils
{
    public class DBOperation
    {
        
        public static void InsertUser(string number, string price)
        {
            string _path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Database");
            string _databaseFilePath = Path.Combine(_path, "myDB.db");
            using (var connection = new SQLiteConnection($"Data Source={_databaseFilePath};Version=3;"))
            {
                connection.Open();

                string insertQuery = "INSERT INTO Users (Number, Price) VALUES (@Number, @Price);";

                using (var command = new SQLiteCommand(insertQuery, connection))
                {
                    command.Parameters.AddWithValue("@Number", number);
                    command.Parameters.AddWithValue("@Price", price);

                    command.ExecuteNonQuery();
                    Console.WriteLine("User inserted.");
                }
            }
        }
    }
}
