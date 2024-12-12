using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.IO;
using UIDesign.Model;

namespace UIDesign.utils
{
    public class DBOperation
    {
        
        public bool AddRecord(int number, double price)
        {
            DBModel record = new DBModel
            {
                DbInstanceUID = Guid.NewGuid().ToString(),
                Number = Convert.ToInt32(number),
                Price = Convert.ToInt32(price)
            };

            return InsertReportRecord(record);
        }


        private bool InsertReportRecord(DBModel record)
        {
            int count = DBManger.Instance.Insert<DBModel>(record);
            if (count > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
