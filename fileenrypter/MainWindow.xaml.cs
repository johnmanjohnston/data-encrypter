using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using Microsoft.Win32;
using System.Windows.Forms;

namespace fileencrypter
{
    public partial class MainWindow : Window
    {
        public static string TargetDirectoryPath = "";
        private readonly string safelyEncryptedPlaceholder = "Don't delete this file, this is essential to make sure your files are recoverable when using an incorrect decryption key.";
        private readonly string safeleyEncryptedFilename = ".fileencrypter_decryptionchecker.txt";

        public MainWindow()
        {
            InitializeComponent();

        }
        
        private void SelectPath(Object sender, RoutedEventArgs e)
        {
            // Select directory
            using (var dialog = new FolderBrowserDialog())
            {
                FolderBrowserDialog folderSelectionDlg = new();
                var result = folderSelectionDlg.ShowDialog();

                if (result.ToString() != string.Empty)
                {
                    TargetDirectoryPath = folderSelectionDlg.SelectedPath;
                }  
                else
                {
                    TargetDirectoryPath = "";
                    System.Windows.Forms.MessageBox.Show("Select a valid path!");
                }
            }

            // Display dir path to user
            if (TargetDirectoryPath != null)
            {
                filepathLabel.Content = $"Directory Path: {TargetDirectoryPath}";
            } 
            else 
            {
                filepathLabel.Content = "No directory selected";
            }
        }

        private bool ValidModificationParameters()
        {
            if (TargetDirectoryPath == "")
            {
                System.Windows.Forms.MessageBox.Show("Select a directory path before encrypting/decrypting");
                return false;
            }

            if (encKeyInput.Text == "")
            {
                System.Windows.Forms.MessageBox.Show("Input a decryption key to encrypt/decrypt your files.");
                return false;
            }

            return true;
        }

        private void EncryptDataClick(Object sender, RoutedEventArgs e)
        {
            if (!ValidModificationParameters())
            {
                return;
            }

            DirectoryInfo dirInfo = new(TargetDirectoryPath);
            FileInfo[] files = dirInfo.GetFiles();

            // Create a file in this dir
            using (FileStream fs = File.Create($"{TargetDirectoryPath}/{safeleyEncryptedFilename}"))
            {
                Byte[] info = new UTF8Encoding(true)
                         .GetBytes(safelyEncryptedPlaceholder);
                fs.Write(info, 0, info.Length);
            }
            

            foreach (FileInfo file in files)
            {
                string fileName = file.Name;
                string fileData = File.ReadAllText($"{TargetDirectoryPath}/{fileName}");
                string encryptedData = EncryptionHandler.GetEncryptedData(fileData, encKeyInput.Text);

                File.WriteAllText($"{TargetDirectoryPath}/{fileName}", encryptedData);
            }
        }

        private void DecryptDataClick(Object sender, RoutedEventArgs e)
        {
            if (!ValidModificationParameters())
            {
                return;
            }

            DirectoryInfo dirInfo = new(TargetDirectoryPath);
            FileInfo[] files = dirInfo.GetFiles();

            /*
            string safeEncryptionText = File.ReadAllText($"{TargetDirectoryPath}/{safeleyEncryptedFilename}");
            safeEncryptionText = EncryptionHandler.GetDecryptedData(safeEncryptionText, encKeyInput.Text);
            if (!(safeEncryptionText == safelyEncryptedPlaceholder))
            {
                System.Windows.Forms.MessageBox.Show("Incorrect encryption key!");
                return;
            } */

            foreach (FileInfo file in files)
            {
                string fileName = file.Name;
                string fileData = File.ReadAllText($"{TargetDirectoryPath}/{fileName}");
                string? decryptedData = EncryptionHandler.GetDecryptedData(fileData, encKeyInput.Text);

                if (decryptedData == null)
                {
                    System.Windows.Forms.MessageBox.Show("Incorrect decryption key!");
                    return;
                }

                File.WriteAllText($"{TargetDirectoryPath}/{fileName}", decryptedData);
            }
        }
    }
}
