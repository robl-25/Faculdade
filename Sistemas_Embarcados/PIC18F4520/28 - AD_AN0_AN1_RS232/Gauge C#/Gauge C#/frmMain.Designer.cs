namespace ExemploGauge
{
    partial class frmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.spGauge = new System.IO.Ports.SerialPort(this.components);
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.lblAlarme0 = new System.Windows.Forms.Label();
            this.lblAlarme1 = new System.Windows.Forms.Label();
            this.pgCanal0 = new System.Windows.Forms.ProgressBar();
            this.pgCanal1 = new System.Windows.Forms.ProgressBar();
            this.gaCanal1 = new AGaugeApp.AGauge();
            this.gaCanal0 = new AGaugeApp.AGauge();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 10;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // lblAlarme0
            // 
            this.lblAlarme0.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblAlarme0.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAlarme0.Location = new System.Drawing.Point(12, 9);
            this.lblAlarme0.Name = "lblAlarme0";
            this.lblAlarme0.Size = new System.Drawing.Size(203, 18);
            this.lblAlarme0.TabIndex = 1;
            this.lblAlarme0.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblAlarme1
            // 
            this.lblAlarme1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblAlarme1.Font = new System.Drawing.Font("Tahoma", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAlarme1.Location = new System.Drawing.Point(227, 9);
            this.lblAlarme1.Name = "lblAlarme1";
            this.lblAlarme1.Size = new System.Drawing.Size(203, 18);
            this.lblAlarme1.TabIndex = 3;
            this.lblAlarme1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // pgCanal0
            // 
            this.pgCanal0.Location = new System.Drawing.Point(12, 152);
            this.pgCanal0.Name = "pgCanal0";
            this.pgCanal0.Size = new System.Drawing.Size(203, 24);
            this.pgCanal0.Step = 1;
            this.pgCanal0.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.pgCanal0.TabIndex = 4;
            // 
            // pgCanal1
            // 
            this.pgCanal1.Location = new System.Drawing.Point(227, 152);
            this.pgCanal1.Name = "pgCanal1";
            this.pgCanal1.Size = new System.Drawing.Size(203, 24);
            this.pgCanal1.Step = 1;
            this.pgCanal1.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.pgCanal1.TabIndex = 5;
            // 
            // gaCanal1
            // 
            this.gaCanal1.BackColor = System.Drawing.SystemColors.Control;
            this.gaCanal1.BaseArcColor = System.Drawing.Color.DimGray;
            this.gaCanal1.BaseArcRadius = 80;
            this.gaCanal1.BaseArcStart = 200;
            this.gaCanal1.BaseArcSweep = 140;
            this.gaCanal1.BaseArcWidth = 2;
            this.gaCanal1.Cap_Idx = AGaugeApp.AGauge.CapIdx.Cap_0;
            this.gaCanal1.CapColor = System.Drawing.Color.Navy;
            this.gaCanal1.CapColors = new System.Drawing.Color[] {
        System.Drawing.Color.Navy,
        System.Drawing.Color.Green,
        System.Drawing.Color.Black,
        System.Drawing.Color.Black,
        System.Drawing.Color.Black};
            this.gaCanal1.CapPosition = new System.Drawing.Point(140, 120);
            this.gaCanal1.CapsPosition = new System.Drawing.Point[] {
        new System.Drawing.Point(140, 120),
        new System.Drawing.Point(10, 120),
        new System.Drawing.Point(10, 10),
        new System.Drawing.Point(10, 10),
        new System.Drawing.Point(10, 10)};
            this.gaCanal1.CapsText = new string[] {
        "Canal AD 1",
        "Valor: 1024",
        "",
        "",
        ""};
            this.gaCanal1.CapText = "Canal AD 1";
            this.gaCanal1.Center = new System.Drawing.Point(100, 120);
            this.gaCanal1.Location = new System.Drawing.Point(227, 12);
            this.gaCanal1.MaxValue = 1100F;
            this.gaCanal1.MinValue = 0F;
            this.gaCanal1.Name = "gaCanal1";
            this.gaCanal1.NeedleColor1 = AGaugeApp.AGauge.NeedleColorEnum.Gray;
            this.gaCanal1.NeedleColor2 = System.Drawing.Color.DimGray;
            this.gaCanal1.NeedleRadius = 80;
            this.gaCanal1.NeedleType = AGaugeApp.AGauge.Pointers.Arrow;
            this.gaCanal1.NeedleWidth = 2;
            this.gaCanal1.Range_Idx = AGaugeApp.AGauge.RangeIdx.Range_0;
            this.gaCanal1.RangeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.gaCanal1.RangeEnabled = true;
            this.gaCanal1.RangeEndValue = 200F;
            this.gaCanal1.RangeInnerRadius = 70;
            this.gaCanal1.RangeOuterRadius = 80;
            this.gaCanal1.RangesColor = new System.Drawing.Color[] {
        System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192))))),
        System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192))))),
        System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192))))),
        System.Drawing.SystemColors.Control,
        System.Drawing.SystemColors.Control};
            this.gaCanal1.RangesEnabled = new bool[] {
        true,
        true,
        true,
        false,
        false};
            this.gaCanal1.RangesEndValue = new float[] {
        200F,
        900F,
        1100F,
        0F,
        0F};
            this.gaCanal1.RangesInnerRadius = new int[] {
        70,
        70,
        70,
        70,
        70};
            this.gaCanal1.RangesOuterRadius = new int[] {
        80,
        80,
        80,
        80,
        80};
            this.gaCanal1.RangesStartValue = new float[] {
        0F,
        200F,
        900F,
        0F,
        0F};
            this.gaCanal1.RangeStartValue = 0F;
            this.gaCanal1.ScaleLinesInterColor = System.Drawing.Color.Black;
            this.gaCanal1.ScaleLinesInterInnerRadius = 73;
            this.gaCanal1.ScaleLinesInterOuterRadius = 80;
            this.gaCanal1.ScaleLinesInterWidth = 1;
            this.gaCanal1.ScaleLinesMajorColor = System.Drawing.Color.Black;
            this.gaCanal1.ScaleLinesMajorInnerRadius = 70;
            this.gaCanal1.ScaleLinesMajorOuterRadius = 80;
            this.gaCanal1.ScaleLinesMajorStepValue = 100F;
            this.gaCanal1.ScaleLinesMajorWidth = 2;
            this.gaCanal1.ScaleLinesMinorColor = System.Drawing.Color.Gray;
            this.gaCanal1.ScaleLinesMinorInnerRadius = 75;
            this.gaCanal1.ScaleLinesMinorNumOf = 3;
            this.gaCanal1.ScaleLinesMinorOuterRadius = 80;
            this.gaCanal1.ScaleLinesMinorWidth = 1;
            this.gaCanal1.ScaleNumbersColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.gaCanal1.ScaleNumbersFormat = null;
            this.gaCanal1.ScaleNumbersRadius = 95;
            this.gaCanal1.ScaleNumbersRotation = 0;
            this.gaCanal1.ScaleNumbersStartScaleLine = 0;
            this.gaCanal1.ScaleNumbersStepScaleLines = 1;
            this.gaCanal1.Size = new System.Drawing.Size(203, 134);
            this.gaCanal1.TabIndex = 2;
            this.gaCanal1.Value = 0F;
            this.gaCanal1.ValueInRangeChanged += new AGaugeApp.AGauge.ValueInRangeChangedDelegate(this.gaCanal1_ValueInRangeChanged);
            // 
            // gaCanal0
            // 
            this.gaCanal0.BackColor = System.Drawing.SystemColors.Control;
            this.gaCanal0.BaseArcColor = System.Drawing.Color.Gray;
            this.gaCanal0.BaseArcRadius = 80;
            this.gaCanal0.BaseArcStart = 200;
            this.gaCanal0.BaseArcSweep = 140;
            this.gaCanal0.BaseArcWidth = 2;
            this.gaCanal0.Cap_Idx = AGaugeApp.AGauge.CapIdx.Cap_1;
            this.gaCanal0.CapColor = System.Drawing.Color.Green;
            this.gaCanal0.CapColors = new System.Drawing.Color[] {
        System.Drawing.Color.Navy,
        System.Drawing.Color.Green,
        System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128))))),
        System.Drawing.Color.Black,
        System.Drawing.Color.Black};
            this.gaCanal0.CapPosition = new System.Drawing.Point(10, 120);
            this.gaCanal0.CapsPosition = new System.Drawing.Point[] {
        new System.Drawing.Point(140, 120),
        new System.Drawing.Point(10, 120),
        new System.Drawing.Point(10, 10),
        new System.Drawing.Point(10, 10),
        new System.Drawing.Point(10, 10)};
            this.gaCanal0.CapsText = new string[] {
        "Canal AD 0",
        "Valor: 1024",
        "",
        "",
        ""};
            this.gaCanal0.CapText = "Valor: 1024";
            this.gaCanal0.Center = new System.Drawing.Point(100, 120);
            this.gaCanal0.Location = new System.Drawing.Point(12, 12);
            this.gaCanal0.MaxValue = 1100F;
            this.gaCanal0.MinValue = 0F;
            this.gaCanal0.Name = "gaCanal0";
            this.gaCanal0.NeedleColor1 = AGaugeApp.AGauge.NeedleColorEnum.Gray;
            this.gaCanal0.NeedleColor2 = System.Drawing.Color.DimGray;
            this.gaCanal0.NeedleRadius = 80;
            this.gaCanal0.NeedleType = AGaugeApp.AGauge.Pointers.Arrow;
            this.gaCanal0.NeedleWidth = 2;
            this.gaCanal0.Range_Idx = AGaugeApp.AGauge.RangeIdx.Range_0;
            this.gaCanal0.RangeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.gaCanal0.RangeEnabled = true;
            this.gaCanal0.RangeEndValue = 200F;
            this.gaCanal0.RangeInnerRadius = 70;
            this.gaCanal0.RangeOuterRadius = 80;
            this.gaCanal0.RangesColor = new System.Drawing.Color[] {
        System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192))))),
        System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192))))),
        System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192))))),
        System.Drawing.SystemColors.Control,
        System.Drawing.SystemColors.Control};
            this.gaCanal0.RangesEnabled = new bool[] {
        true,
        true,
        true,
        false,
        false};
            this.gaCanal0.RangesEndValue = new float[] {
        200F,
        900F,
        1100F,
        0F,
        0F};
            this.gaCanal0.RangesInnerRadius = new int[] {
        70,
        70,
        70,
        70,
        70};
            this.gaCanal0.RangesOuterRadius = new int[] {
        80,
        80,
        80,
        80,
        80};
            this.gaCanal0.RangesStartValue = new float[] {
        0F,
        200F,
        900F,
        0F,
        0F};
            this.gaCanal0.RangeStartValue = 0F;
            this.gaCanal0.ScaleLinesInterColor = System.Drawing.Color.Black;
            this.gaCanal0.ScaleLinesInterInnerRadius = 73;
            this.gaCanal0.ScaleLinesInterOuterRadius = 80;
            this.gaCanal0.ScaleLinesInterWidth = 1;
            this.gaCanal0.ScaleLinesMajorColor = System.Drawing.Color.Black;
            this.gaCanal0.ScaleLinesMajorInnerRadius = 70;
            this.gaCanal0.ScaleLinesMajorOuterRadius = 80;
            this.gaCanal0.ScaleLinesMajorStepValue = 100F;
            this.gaCanal0.ScaleLinesMajorWidth = 2;
            this.gaCanal0.ScaleLinesMinorColor = System.Drawing.Color.Gray;
            this.gaCanal0.ScaleLinesMinorInnerRadius = 75;
            this.gaCanal0.ScaleLinesMinorNumOf = 3;
            this.gaCanal0.ScaleLinesMinorOuterRadius = 80;
            this.gaCanal0.ScaleLinesMinorWidth = 1;
            this.gaCanal0.ScaleNumbersColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.gaCanal0.ScaleNumbersFormat = null;
            this.gaCanal0.ScaleNumbersRadius = 95;
            this.gaCanal0.ScaleNumbersRotation = 0;
            this.gaCanal0.ScaleNumbersStartScaleLine = 0;
            this.gaCanal0.ScaleNumbersStepScaleLines = 1;
            this.gaCanal0.Size = new System.Drawing.Size(203, 134);
            this.gaCanal0.TabIndex = 0;
            this.gaCanal0.Value = 0F;
            this.gaCanal0.ValueInRangeChanged += new AGaugeApp.AGauge.ValueInRangeChangedDelegate(this.gaCanal0_ValueInRangeChanged);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(443, 188);
            this.Controls.Add(this.pgCanal1);
            this.Controls.Add(this.pgCanal0);
            this.Controls.Add(this.lblAlarme1);
            this.Controls.Add(this.gaCanal1);
            this.Controls.Add(this.lblAlarme0);
            this.Controls.Add(this.gaCanal0);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "frmMain";
            this.Text = "Exemplo de Gauge [Uitlizando COM1]";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.IO.Ports.SerialPort spGauge;
        private AGaugeApp.AGauge gaCanal0;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label lblAlarme0;
        private System.Windows.Forms.Label lblAlarme1;
        private AGaugeApp.AGauge gaCanal1;
        private System.Windows.Forms.ProgressBar pgCanal0;
        private System.Windows.Forms.ProgressBar pgCanal1;
    }
}

