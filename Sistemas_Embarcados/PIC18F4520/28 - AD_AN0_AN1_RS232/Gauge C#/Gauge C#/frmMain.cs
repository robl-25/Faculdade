using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ExemploGauge
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            try
            {
                pgCanal0.Maximum = (int)gaCanal0.MaxValue;
                pgCanal0.Minimum = (int)gaCanal0.MinValue;
                pgCanal1.Maximum = (int)gaCanal1.MaxValue;
                pgCanal1.Minimum = (int)gaCanal1.MinValue;
                spGauge.Open();
            }
            catch
            {
                MessageBox.Show("Porta COM1 já está em uso!");
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string Valor1 = spGauge.ReadExisting();
            if (Valor1.Length > 0) 
            {
                decode_serial(Valor1);
            }
        }

        private void decode_serial(string Valor)
        {
            int count;
            string[] Teste = Valor.Split('\x04');
            for (count = 0; count < Teste.Length; count++)
            {
                try
                {
                    if (Teste[count].Length >= 9)
                    {
                        if (Teste[count].Substring(1, 4).CompareTo("AN0=") == 0) //Verfica se é inicio do frame
                        {
                            gaCanal0.Value = Int16.Parse(Teste[count].Substring(5, 4), System.Globalization.NumberStyles.HexNumber);
                            gaCanal0.Cap_Idx = AGaugeApp.AGauge.CapIdx.Cap_1;
                            gaCanal0.CapText = "Valor:" + gaCanal0.Value.ToString();
                            pgCanal0.Value = (int)gaCanal0.Value;
                        }
                        if (Teste[count].Substring(1, 4).CompareTo("AN1=") == 0)  //Verfica se é inicio do frame
                        {
                            gaCanal1.Value = Int16.Parse(Teste[count].Substring(5, 4), System.Globalization.NumberStyles.HexNumber);
                            gaCanal1.Cap_Idx = AGaugeApp.AGauge.CapIdx.Cap_1;
                            gaCanal1.CapText = "Valor:" + gaCanal1.Value.ToString();
                            pgCanal1.Value = (int)gaCanal1.Value;
                        }
                    }
                }
                finally
                {

                }
            }
        }

        private void gaCanal0_ValueInRangeChanged(object sender, AGaugeApp.AGauge.ValueInRangeChangedEventArgs e)
        {
            switch (e.valueInRange){
                case AGaugeApp.AGauge.RangeIdx.Range_0: //Alarme Baixo
                    lblAlarme0.BackColor = Color.DarkGreen;
                    lblAlarme0.ForeColor = Color.LightGreen;
                    lblAlarme0.Text = "Alarme Baixo Acionado!";
                    break;
                case AGaugeApp.AGauge.RangeIdx.Range_1: //Alarme Médio
                    lblAlarme0.BackColor = Color.Goldenrod;
                    lblAlarme0.ForeColor = Color.LightYellow;
                    lblAlarme0.Text = "Alarme Médio Acionado!";
                    break;
                case AGaugeApp.AGauge.RangeIdx.Range_2: //Alarme Máximo
                    lblAlarme0.BackColor = Color.DarkRed;
                    lblAlarme0.ForeColor = Color.Red;
                    lblAlarme0.Text = "Alarme Máximo Acionado!";
                    break;
            }
        }

        private void gaCanal1_ValueInRangeChanged(object sender, AGaugeApp.AGauge.ValueInRangeChangedEventArgs e)
        {
            switch (e.valueInRange)
            {
                case AGaugeApp.AGauge.RangeIdx.Range_0: //Alarme Baixo
                    lblAlarme1.BackColor = Color.DarkGreen;
                    lblAlarme1.ForeColor = Color.LightGreen;
                    lblAlarme1.Text = "Alarme Baixo Acionado!";
                    break;
                case AGaugeApp.AGauge.RangeIdx.Range_1: //Alarme Médio
                    lblAlarme1.BackColor = Color.Goldenrod;
                    lblAlarme1.ForeColor = Color.LightYellow;
                    lblAlarme1.Text = "Alarme Médio Acionado!";
                    break;
                case AGaugeApp.AGauge.RangeIdx.Range_2: //Alarme Máximo
                    lblAlarme1.BackColor = Color.DarkRed;
                    lblAlarme1.ForeColor = Color.Red;
                    lblAlarme1.Text = "Alarme Máximo Acionado!";
                    break;
            }
        }
    }
}
