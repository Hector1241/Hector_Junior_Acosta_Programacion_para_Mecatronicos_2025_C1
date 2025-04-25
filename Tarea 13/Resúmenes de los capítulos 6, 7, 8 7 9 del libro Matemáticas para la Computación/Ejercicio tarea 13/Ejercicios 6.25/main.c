def es_reflexiva(M):
    for i in range(len(M)):
        if M[i][i] != 1:
            return False
    return True
