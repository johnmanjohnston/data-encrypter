using System;
using System.IO;
using System.Text;
using System.Security.Cryptography;

namespace fileencrypter
{
    public class EncryptionHandler
    {
        public static string GetEncryptedData(string fileData, string key)
        {
            byte[] bytesData = Encoding.Unicode.GetBytes(fileData);
            using (Aes aesEncryptor = Aes.Create())
            {
                Rfc2898DeriveBytes pdb = new(key, new byte[] { 0x49, 0x76, 0x61, 0x6e, 0x20, 0x4d, 0x65, 0x64, 0x76, 0x65, 0x64, 0x65, 0x76 }); // tf?
                aesEncryptor.Key = pdb.GetBytes(32);
                aesEncryptor.IV = pdb.GetBytes(16);

                using (MemoryStream memStream = new())
                {
                    using (CryptoStream cs = new(memStream, aesEncryptor.CreateEncryptor(), CryptoStreamMode.Write))
                    {
                        cs.Write(bytesData, 0, bytesData.Length);
                        cs.Close();
                    }

                    fileData = Convert.ToBase64String(memStream.ToArray());
                }
            }

            return fileData;
        }

        public static string? GetDecryptedData(string fileData, string key)
        {
            fileData = fileData.Replace(" ", "+");
            byte[] cipherBytes = Convert.FromBase64String(fileData);
            using (Aes aesEncryptor = Aes.Create())
            {
                Rfc2898DeriveBytes pdb = new(key, new byte[] { 0x49, 0x76, 0x61, 0x6e, 0x20, 0x4d, 0x65, 0x64, 0x76, 0x65, 0x64, 0x65, 0x76 });
                aesEncryptor.Key = pdb.GetBytes(32);
                aesEncryptor.IV = pdb.GetBytes(16);

                try
                {
                    using MemoryStream memStream = new();
                    using (CryptoStream cs = new(memStream, aesEncryptor.CreateDecryptor(), CryptoStreamMode.Write))
                    {
                        cs.Write(cipherBytes, 0, cipherBytes.Length);
                        cs.Close();
                    }



                    fileData = Encoding.Unicode.GetString(memStream.ToArray());
                }
                
                catch (CryptographicException)
                {
                    return null;
                }
            }

            return fileData;
        }
    }
}
