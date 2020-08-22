using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;
using System.Web;
using System.Net;

namespace Universal_Activation_Tool
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void activatebut_Click(object sender, EventArgs e)
        {
            //string verifystr = "{";
            //Random random = new Random();
            //int temp;
            string address = @"https://raw.githubusercontent.com/djdjz7/AAS/Switcher/keynew";
            string keyenteredstring = keyenter.Text + "\n";
            WebClient web = new WebClient();
            log.AppendText("Getting correct key from the Internet...");
            string keydownload = web.DownloadString(address);
            progressBar1.Value = 30;
            log.AppendText("Done.\r\nComparing keys...");
            if (keyenteredstring==keydownload)
            {
                log.AppendText("Key is correct.\r\nWriting SN...");
                progressBar1.Value = 70;
                File.WriteAllText(@".\Resources\Activate.sact", @"{15S9A47U6}");
                if(File.Exists(@".\config\DEMO"))
                    File.Delete(@".\config\DEMO");
                log.AppendText("Done.\r\nActivation Complete.\r\n");
                progressBar1.Value = 100;

            }
            else
            {
                log.AppendText("Key is incorrect.\r\nActivation Aborted: Key Incorrect.\r\n");
                progressBar1.Value = 0;
            }
        }
    }
}
