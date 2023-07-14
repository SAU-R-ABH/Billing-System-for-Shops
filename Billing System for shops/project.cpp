#include <iostream>
#include <vector>
#include <string>

// Product entity
struct Product {
    std::string name;
    double price;
    int quantity;
};

// Invoice entity
struct Invoice {
    std::vector<Product> products;
    double totalAmount;
};

// Function to calculate the total amount of an invoice
double calculateTotalAmount(const std::vector<Product>& products) {
    double total = 0.0;
    for (const auto& product : products) {
        total += product.price * product.quantity;
    }
    return total;
}

// Function to generate an invoice
Invoice generateInvoice(const std::vector<Product>& products) {
    double totalAmount = calculateTotalAmount(products);
    return { products, totalAmount };
}

// Function to display an invoice
void displayInvoice(const Invoice& invoice) {
    std::cout << "Invoice Details:\n";
    std::cout << "-----------------\n";
    for (const auto& product : invoice.products) {
        std::cout << "Product: " << product.name << ", Price: $" << product.price << ", Quantity: " << product.quantity << std::endl;
    }
    std::cout << "-----------------\n";
    std::cout << "Total Amount: $" << invoice.totalAmount << std::endl;
}

// Function to process payment
void processPayment(double amount, std::string paymentMethod) {
    // Placeholder implementation for payment processing
    std::cout << "Processing payment of $" << amount << " using " << paymentMethod << std::endl;
    std::cout << "Payment successful!" << std::endl;
}

// Function to scan barcode
std::string scanBarcode() {
    // Placeholder implementation for barcode scanning
    std::string barcode;
    std::cout << "Scan the barcode: ";
    std::cin >> barcode;
    return barcode;
}

int main() {
    // Create sample products
    std::vector<Product> products = {
        { "Product 1", 10.0, 2 },
        { "Product 2", 15.0, 1 },
        { "Product 3", 20.0, 3 }
    };

    // Generate and display an invoice
    Invoice invoice = generateInvoice(products);
    displayInvoice(invoice);

    // Process payment
    double amountToPay = invoice.totalAmount;
    std::string paymentMethod;
    std::cout << "Enter payment method (e.g., cash, credit card): ";
    std::cin >> paymentMethod;
    processPayment(amountToPay, paymentMethod);

    // Scan barcode
    std::string scannedBarcode = scanBarcode();
    std::cout << "Scanned barcode: " << scannedBarcode << std::endl;

    return 0;
}
