word1 = 'Кот'
word2 = 'Ток'

def check_anagram(word1, word2):
    try:
        word1 = word1.lower()
        word2 = word2.lower()

        word1 = sorted(word1)
        word2 = sorted(word2)

        if (word1 == word2):
            print('Два слова являются анограммами')
        else:
            print('Два слова не являются анограммами')
    except KeyboardInterrupt:
        print("\nПрограмма прервана пользователем")
        
    except Exception as e:
        print(f"Непредвиденная ошибка: {e}")
        
    finally:
        print("\nЗавершение проверки")
        print("Спасибо за использование программы!")

check_anagram(word1, word2)