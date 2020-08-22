namespace Universal_Activation_Tool
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.keyenter = new System.Windows.Forms.MaskedTextBox();
            this.activatebut = new System.Windows.Forms.Button();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.header = new System.Windows.Forms.Label();
            this.enterkeyexplain = new System.Windows.Forms.Label();
            this.log = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // keyenter
            // 
            this.keyenter.AsciiOnly = true;
            this.keyenter.Culture = new System.Globalization.CultureInfo("en-001");
            this.keyenter.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.keyenter.ImeMode = System.Windows.Forms.ImeMode.Disable;
            this.keyenter.Location = new System.Drawing.Point(20, 74);
            this.keyenter.Mask = ">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA";
            this.keyenter.Name = "keyenter";
            this.keyenter.PromptChar = ' ';
            this.keyenter.Size = new System.Drawing.Size(271, 26);
            this.keyenter.TabIndex = 0;
            // 
            // activatebut
            // 
            this.activatebut.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.activatebut.Location = new System.Drawing.Point(297, 76);
            this.activatebut.Name = "activatebut";
            this.activatebut.Size = new System.Drawing.Size(75, 23);
            this.activatebut.TabIndex = 1;
            this.activatebut.Text = "Activate";
            this.activatebut.UseVisualStyleBackColor = true;
            this.activatebut.Click += new System.EventHandler(this.activatebut_Click);
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(20, 106);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(352, 23);
            this.progressBar1.TabIndex = 2;
            // 
            // header
            // 
            this.header.AutoSize = true;
            this.header.Font = new System.Drawing.Font("Segoe UI", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.header.Location = new System.Drawing.Point(12, 9);
            this.header.Name = "header";
            this.header.Size = new System.Drawing.Size(172, 47);
            this.header.TabIndex = 3;
            this.header.Text = "Activator";
            // 
            // enterkeyexplain
            // 
            this.enterkeyexplain.AutoSize = true;
            this.enterkeyexplain.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.enterkeyexplain.Location = new System.Drawing.Point(17, 56);
            this.enterkeyexplain.Name = "enterkeyexplain";
            this.enterkeyexplain.Size = new System.Drawing.Size(121, 15);
            this.enterkeyexplain.TabIndex = 4;
            this.enterkeyexplain.Text = "Please enter your key:";
            // 
            // log
            // 
            this.log.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.log.ImeMode = System.Windows.Forms.ImeMode.Disable;
            this.log.Location = new System.Drawing.Point(20, 135);
            this.log.Multiline = true;
            this.log.Name = "log";
            this.log.ReadOnly = true;
            this.log.Size = new System.Drawing.Size(352, 86);
            this.log.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(398, 233);
            this.Controls.Add(this.log);
            this.Controls.Add(this.enterkeyexplain);
            this.Controls.Add(this.header);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.activatebut);
            this.Controls.Add(this.keyenter);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Activator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MaskedTextBox keyenter;
        private System.Windows.Forms.Button activatebut;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Label header;
        private System.Windows.Forms.Label enterkeyexplain;
        private System.Windows.Forms.TextBox log;
    }
}

