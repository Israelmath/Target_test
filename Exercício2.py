def fibo(final):
    """
    Função devolve uma lista com a sequencia de Fibonacci até o elemento de posição {final}.
    :param final: Inteiro limitante da lista com a sequência de Fibonacci.
    :return: Lista contendo {final} elementos da sequencia de Fibonacci.
    """
    prox = 0
    fibonacci = [0]
    fibob = 1

    if final == 0:
        return [0]
    else:
        for i in range(final - 1):
            prox = fibonacci[i] + fibob
            fibonacci.append(fibob)
            fibob = prox

        return fibonacci

def busca_recursiva(num, fibo_dividida):
    """
    Função que busca, recursivamente, um elemento de uma lista.
    :param num: Número buscado na lista (sequencia).
    :param fibo_dividida: Lista (Fibonacci) alvo da nossa busca.
    :return: String informando se a sequência possui o elemento buscado.
    """
    qtd_elementos = len(fibo_dividida)
    print(fibo_dividida)
    if qtd_elementos == 1:
        if num == fibo_dividida[0]:
            return f'O número {num} pertence à sequência de Fibonacci'
        else:
            return f'O número {num} não pertence à sequência de Fibonacci'
    else:
        if fibo_dividida[len(fibo_dividida) // 2] > num:
            return busca_recursiva(num, fibo_dividida[:len(fibo_dividida) // 2])
        else:
            return busca_recursiva(num, fibo_dividida[len(fibo_dividida) // 2:])

def main():
    """
    Através de um input do usuário, a função 'main' ativa os outros eventos para iniciar
    a busca pelo número requisitado.
    :return: null
    """

    num = int(input('Digite o número a ser buscado: '))

    if num > 10:
        save_fibo = fibo(num)
        resposta = busca_recursiva(num, save_fibo)
        print(resposta)
    else:
        save_fibo = fibo(num+2)
        resposta = busca_recursiva(num, save_fibo)
        print(resposta)

main()