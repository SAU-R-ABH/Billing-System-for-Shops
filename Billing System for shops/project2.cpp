#include <iostream>
#include <zxing/common/GlobalHistogramBinarizer.h>
#include <zxing/qrcode/QRCodeWriter.h>
#include <zxing/BarcodeFormat.h>
#include <zxing/EncodeHints.h>
#include <zxing/BinaryBitmap.h>
#include <zxing/qrcode/QRCodeReader.h>
#include <zxing/common/GlobalHistogramBinarizer.h>
#include <zxing/MultiFormatReader.h>
#include <zxing/Result.h>
#include <zxing/ResultMetadata.h>
#include <zxing/ReaderException.h>
#include <zxing/LuminanceSource.h>
#include <zxing/Binarizer.h>
#include <zxing/common/HybridBinarizer.h>
#include <zxing/common/Counted.h>

// Function to generate a QR code barcode and return the barcode as a string
std::string generateQRCodeBarcode(const std::string& data, int width, int height) {
    using namespace zxing;
    using namespace zxing::qrcode;

    // Create QR code writer
    Ref<Writer> writer(new QRCodeWriter());

    // Create encode hints
    EncodeHints hints(BarcodeFormat::QR_CODE);
    hints.setMargin(0);  // Set margin to 0 (no white space around the barcode)

    // Encode data and generate barcode
    BitMatrix bitMatrix = writer->encode(data, BarcodeFormat::QR_CODE, width, height, hints);

    // Convert barcode to string representation
    std::string barcode;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            barcode += bitMatrix.get(x, y) ? "1" : "0";
        }
    }
    return barcode;
}

int main() {
    // Generate QR code barcode
    std::string data = "Hello, World!";
    int width = 256;
    int height = 256;
    std::string barcode = generateQRCodeBarcode(data, width, height);

    // Display the generated barcode
    std::cout << "Generated Barcode: " << std::endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << (barcode[y * width + x] == '1' ? "#" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
