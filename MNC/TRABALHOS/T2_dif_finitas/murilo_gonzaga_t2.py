import os, time
import math
import matplotlib.pyplot as mpt

#variaveis globais => informações da tabela fornecida
times = [0, 3, 5, 8, 10, 13]
distances = [0, 225, 383, 623, 742, 993]
derivadas_regressão = [76.3073788546256, 76.1573788546256, 76.0573788546256, 75.9073788546256, 75.8073788546256, 75.6573788546256] #Derivadas obtidas usando o polinômio de regressão obtido pelo geogebra: f(x) = -0.025x^2 + 76.3073788546256x - 0.1354625559661

#methods

def diff_prog(i): #diferença finita progressiva
    
    if i < len(times) - 1:
        h = times[i + 1] - times[i]
        return (distances[i + 1] - distances[i]) / h
    return None

def diff_reg(i): #diferença finita regressiva
    
    if i > 0:
        h = times[i] - times[i - 1]
        return (distances[i] - distances[i - 1]) / h
    return None

def diff_cent(i): #diferença finita central
    
    if i > 0 and i < len(times) - 1:
        h = (times[i + 1] - times[i - 1]) / 2
        return (distances[i + 1] - distances[i - 1]) / (2 * h)
    return None
  
#utils
def clear_terminal():
    os.system("cls" if os.name == "nt" else "clear") #limpa terminal      
    
def escolha(): #menu interativo com o usuário
    print("Escolha qual método deseja aplicar na tábela disponivel:")
    print("[1] - Metódos de Diferenças finitas")
    print("[0] - Sair")
    
    return int(input("Digite o numero correspondente: "))

def tabela(): #cópia da tabela do pdf, para melhor visualização do problema
    print("-" * 11, "TABELA", "-" * 11)
    print("-" * 30)
    print("| Tempo (s) | Distância (m)  |")
    print("-" * 30)
    for t, d in zip(times, distances):
        print(f"| {t:<9} | {d:<14} |")
    print("-" * 30)
    print()
    


def plot_grafico(data):
    
    
    #vetor de pontos para representar no grafico
    vp = [linha["vp"] for linha in data]  
    vr = [linha["vr"] for linha in data]
    vc = [linha["vc"] for linha in data]

    mpt.figure(figsize=(10, 5))
    mpt.plot(times, vp, 'o-', label="Progressiva") #linha da progressiva, com bolinhas nos pontos
    mpt.plot(times, vr, 'rs--', label="Regressiva")#linha da regressiva, com quadradinhos nos pontos
    mpt.plot(times, vc, 'kx-.', label="Central") #linha da central, com X nos pontos

    mpt.title("Velocidade Instantânea por Tempo", fontsize=14) #titulo
    mpt.xlabel("Tempo (s)")
    mpt.ylabel("Velocidade (m/s)")
    mpt.grid(True)
    mpt.legend() #atribuindo legenda para o grafico ficar mais informativp
    mpt.tight_layout()
    mpt.savefig("grafico_velocidade.png") #salvando imagem
    mpt.close()
    
def plot_tabelas(data):
    import matplotlib.gridspec as gridspec

    fig = mpt.figure(figsize=(10, 6))
    spec = gridspec.GridSpec(nrows=2, ncols=1, height_ratios=[1, 1]) #usando o gridspec para definir o tamanho de colunas e linhas da nossa imagem

    #primeira tabela
    ax1 = fig.add_subplot(spec[0])
    ax1.axis('off')
    ax1.set_title("Velocidade Instantânea", fontsize=12, pad=5)

    col_labels = ["Tempo (s)", "Regressiva", "Central", "Progressiva"]
    table_data = [
        [
            linha["tempo"],
            f"{linha['vr']:.2f}" if linha["vr"] is not None else "N/A",
            f"{linha['vc']:.2f}" if linha["vc"] is not None else "N/A",
            f"{linha['vp']:.2f}" if linha["vp"] is not None else "N/A",
        ]
        for linha in data
    ]

    tabela1 = ax1.table(cellText=table_data, colLabels=col_labels, loc='center', cellLoc='center')
    tabela1.auto_set_font_size(False)
    tabela1.set_fontsize(9)
    tabela1.scale(1, 1.2)

    #segunda tabela
    ax2 = fig.add_subplot(spec[1])
    ax2.axis('off')
    ax2.set_title("Erros Absolutos em Relação à Derivada Real", fontsize=12, pad=5)

    col_labels2 = ["Tempo", "Erro R.", "Erro C.", "Erro P."]
    table_data2 = [
        [
            linha["tempo"],
            f"{abs(linha['vr'] - derivadas_regressão[i]):.4f}" if linha["vr"] is not None else "N/A",
            f"{abs(linha['vc'] - derivadas_regressão[i]):.4f}" if linha["vc"] is not None else "N/A",
            f"{abs(linha['vp'] - derivadas_regressão[i]):.4f}" if linha["vp"] is not None else "N/A"
        ]
        for i, linha in enumerate(data)
    ]

    tabela2 = ax2.table(cellText=table_data2, colLabels=col_labels2, loc='center', cellLoc='center')
    tabela2.auto_set_font_size(False)
    tabela2.set_fontsize(9)
    tabela2.scale(1, 1.2)

    mpt.tight_layout()
    mpt.savefig("tabelas_velocidade_erro.png")
    mpt.close()
        
    
def relatorio(data):
    print("\nRELATÓRIO:\n")
    print("-" * 60)
    i = 0
    for linha in data:
        
        print(f"Tempo = {linha['tempo']} s")
        print(f"  Regressiva:  {linha['vr']:.2f} m/s || Erro : {abs(linha['vr'] - derivadas_regressão[i]):.4f})" if linha['vr'] else "  Regressiva: N/A")
        print(f"  Central:     {linha['vc']:.2f} m/s || Erro : {abs(linha['vc'] - derivadas_regressão[i]):.4f})" if linha['vc'] else "  Central: N/A")
        print(f"  Progressiva: {linha['vp']:.2f} m/s || Erro : {abs(linha['vp'] - derivadas_regressão[i]):.4f})" if linha['vp'] else "  Progressiva: N/A")
        
        print("-" * 60)
        i += 1

    
def main():
        e = 3
    
        tabela()
        e = escolha()

        while(e != 0 and e != 1): #loop para evitar valores indesejados
            e = int(input("Digite um valor válido (1/0): "))
            
        if e == 1:
            clear_terminal()
            
            data = [] #vetor geral com todas as informacoes, com ideia de passar para outras funcoes conseguirem utilizar todos os dados ao mesmo tempo
            
            for i in range (len(times)): #recebendo dados
                
    
                line = {
                    "tempo": times[i],
                    "distancia": distances[i],
                    "vp": diff_prog(i),
                    "vr": diff_reg(i),
                    "vc": diff_cent(i),         
                }
                data.append(line)
            
            relatorio(data) #plota relatorio no cmd
            plot_grafico(data) #plota grafico
            plot_tabelas(data) #plota tabelas
             
        else:
            clear_terminal() 
        
main()
    
    
