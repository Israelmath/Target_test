import pandas as pd

def main():
    """
    Função principal que tem as seguintes responsabilidades:
    - Atribui à variável {faturamento} os faturamentos mensais;
    - Cria um DataFrame, da biblioteca Pandas, para facilitar os cáculos;
    - Adiciona ao DataFrame criado uma coluna 'Porcentagem (%)' que recebe as porcentagens de participação nos
    rendimentos de cada estado.
    :return: null
    """

    faturamento = [67836.43, 36678.66, 29229.88, 27165.48, 19849.53]

    df = pd.DataFrame(faturamento, columns= ['Faturamento'], index= ['SP', 'RJ', 'MG', 'ES', 'Outros'])

    df['Porcentagem (%)'] = round(df['Faturamento']/df.sum(axis=0)[0]*100, 2)

    print(df.head())

main()