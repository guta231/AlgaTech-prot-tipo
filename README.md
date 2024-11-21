# AlgaTech  
### Contexto  
A Global Solution (GS) é uma metodologia inovadora de avaliação desenvolvida pela FIAP, desafiando alunos a criar soluções tecnológicas para problemas reais. No segundo semestre de 2024, o tema **GREEN ENERGY: Energia Limpa para um Futuro Mais Sustentável** inspirou a criação de projetos que buscam alternativas energéticas sustentáveis.  

Nosso projeto, **AlgaTech**, explora o potencial das **microalgas** como recurso energético renovável e aplica técnicas de **eletrofloculação** para facilitar sua colheita, permitindo sua utilização em áreas como biocombustíveis, tratamento de água e alimentação humana.  

### Equipe do Projeto  
Nome                    | RM  
------------------------ | ------  
Gustavo Henrique de Oliveira | 556712  
Milena Garcia           | 555111  
Enzo Vynicius           | 558225  

### Descrição do Projeto  
O **AlgaTech** é um sistema **totalmente autossustentável**, que utiliza painéis fotovoltaicos para carregar baterias responsáveis pela alimentação de todo o sistema. Ele monitora as condições ideais de crescimento de microalgas em um aquário e realiza sua colheita de forma eficiente através de **eletrofloculação**, um processo que utiliza corrente elétrica para agrupar as microalgas em flocos, facilitando sua separação da água.  

O sistema combina:  
- **Sensores de Temperatura e Luminosidade** para monitorar as condições ideais de crescimento.  
- **Node-RED** como dashboard interativo, exibindo dados em tempo real.  
- **Python** para análise dos dados coletados e gerar feedback sobre as condições ambientais.  
- **Eletrodos de Metal** para realizar o processo de eletrofloculação de forma controlada.  

### Requisitos e Funcionalidades  
O **AlgaTech** foi desenvolvido com os seguintes requisitos:  

* **Sistema Autossustentável:**  
   - Painéis solares fornecem energia ao sistema, carregando baterias recarregáveis que alimentam o Arduino/ESP32 e os sensores.  

* **Monitoramento do Ambiente:**  
   - Sensores enviam dados de temperatura e luminosidade ao dashboard via MQTT.  
   - A luminosidade é medida no formato analógico (0 a 1023), e a temperatura, em graus Celsius.  

* **Análise de Dados com Python:**  
   - Avaliação das condições ideais para o crescimento das microalgas (faixas específicas de temperatura e luminosidade).  
   - Feedback enviado de volta ao Node-RED sobre o estado das condições ambientais.  

* **Processo de Eletrofloculação:**  
   - Eletrodos de metal conduzem corrente elétrica para agrupar as microalgas em flocos.  
   - Controle seguro da corrente elétrica para evitar danos aos componentes do sistema e ao aquário.  

Materiais principais para a implementação:  
- Painéis fotovoltaicos de 5V.  
- Baterias recarregáveis de 3.7V e módulo de carregamento (ex.: TP4056).  
- Sensores de Temperatura (ex.: DHT11 ou DS18B20).  
- Sensor de Luminosidade (ex.: LDR).  
- Eletrodos de metal condutor (ex.: aço inoxidável ou titânio).  
- Placa Arduino ou ESP32.  

### Objetivos  
O objetivo do **AlgaTech** é criar um sistema sustentável e automatizado que:  
- Utilize energia renovável para operar, reduzindo impactos ambientais.  
- Monitore as condições ideais para o crescimento de microalgas e forneça feedback sobre o estado ambiental.  
- Facilite a colheita das microalgas por meio de eletrofloculação eficiente e segura.  
- Promova o uso das microalgas como recurso energético renovável em aplicações como biocombustíveis e produtos sustentáveis.  

### Dashboard no Node-RED  
![Dashboard Node-RED](https://github.com/guta231/AlgaTech-prot-tipo/blob/main/Captura%20de%20tela%202024-11-21%20170131.png)  

[Clique aqui para acessar o Node-RED](http://20.206.203.145:1880/ui)  

### Código Python  
O código utilizado para análise das condições ideais pode ser encontrado neste repositório:  
[Repositório do Projeto](https://github.com/guta231/algatech-python)  

---

O **AlgaTech** demonstra como a inovação tecnológica e a sustentabilidade podem caminhar juntas, criando soluções viáveis para um futuro mais sustentável através da utilização de microalgas e fontes de energia renovável.

---
