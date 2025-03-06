# Arduino Door - Projeto de Controle de Acesso com Teclado e Servo Motor

## Descrição
O projeto **Arduino Door** é um sistema de controle de acesso que utiliza um **Arduino**, um **teclado matricial**, um **display LCD I2C** e um **servo motor** para simular a abertura e fechamento de uma porta mediante a digitação de uma senha correta.

## Componentes Utilizados
- **Arduino** (qualquer modelo compatível)
- **Teclado Matricial 4x3**
- **Display LCD I2C (16x2)**
- **Servo Motor**
- **Jumpers**

## Bibliotecas Utilizadas
Para o funcionamento correto do projeto, é necessário instalar as seguintes bibliotecas no Arduino IDE:
- `Keypad.h` - Para a leitura do teclado matricial.
- `LiquidCrystal_I2C.h` - Para o controle do display LCD via protocolo I2C.
- `Wire.h` - Para comunicação I2C.
- `Servo.h` - Para controle do servo motor.

## Funcionamento
1. Ao iniciar, o display LCD exibe uma mensagem inicial.
2. O sistema espera a entrada de uma senha pelo teclado matricial.
3. Se a senha digitada corresponder à senha mestra predefinida (**123456**), o servo motor se move para abrir a porta e exibe "Porta aberta" no LCD.
4. Para fechar a porta, o usuário deve pressionar `#`, momento em que o servo motor retorna à sua posição original e a mensagem "A porta fechou!" é exibida no LCD.
5. Caso a senha esteja incorreta, o sistema exibe "Senha Errada!" e solicita a senha novamente.

## Código Fonte
O código-fonte do projeto está implementado em C++ e pode ser encontrado no repositório. Ele inicializa os componentes no `setup()` e gerencia a entrada do teclado, verificando a senha e acionando o servo motor no `loop()`.

## Esquemático de Ligação
### Conexões principais:
- **Teclado Matricial:**
  - Linhas conectadas aos pinos **2, 3, 4, 5**
  - Colunas conectadas aos pinos **6, 7, 8**
- **Servo Motor:**
  - Pino de sinal conectado ao **pino 9**
- **Display LCD I2C:**
  - SDA no **A4**, SCL no **A5** (para placas como Arduino Uno)

## Melhorias Futuras
- Implementação de um sistema de alteração dinâmica de senha.
- Integração com sensores RFID para um segundo método de autenticação.
- Uso de um buzzer para alertas de senha incorreta.

## Como Executar
1. Instale as bibliotecas necessárias na Arduino IDE.
2. Carregue o código para a placa Arduino.
3. Conecte os componentes de acordo com o esquema de ligação.
4. Digite a senha correta (**123456**) para abrir a porta.


