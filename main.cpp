#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Criação da janela principal
    QWidget window;
    window.setWindowTitle("Login");
    window.setGeometry(100, 100, 300, 150);

    // Criação dos elementos da interface
    QLabel* usernameLabel = new QLabel("Nome de usuário:", &window);
    QLineEdit* usernameLineEdit = new QLineEdit(&window);
    QLabel* passwordLabel = new QLabel("Senha:", &window);
    QLineEdit* passwordLineEdit = new QLineEdit(&window);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    QPushButton* loginButton = new QPushButton("Login", &window);

    // Posicionamento dos elementos na janela
    usernameLabel->move(20, 20);
    usernameLineEdit->move(120, 20);
    passwordLabel->move(20, 50);
    passwordLineEdit->move(120, 50);
    loginButton->move(120, 90);

    // Conexão do botão de login com a função de verificação
    QObject::connect(loginButton, &QPushButton::clicked, [&]() {
        QString username = usernameLineEdit->text();
        QString password = passwordLineEdit->text();

        QString correctUsername = "admin";
        QString correctPassword = "password";

        if (username == correctUsername && password == correctPassword) {
            QMessageBox::information(&window, "Login", "Login bem-sucedido!");
        } else {
            QMessageBox::warning(&window, "Login", "Nome de usuário ou senha incorretos!");
        }
    });

    // Exibição da janela
    window.show();

    // Início do loop de eventos da aplicação
    return app.exec();
}
