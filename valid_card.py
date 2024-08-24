def luhn_check(card_num):

    digits = [int(x) for x in str(card_num)][::-1]

    for i in range(1, len(digits), 2):
        digits[i] *= 2
        if digits[i] > 9:
            digits[i] = (digits[i] // 10) + (digits[i] % 10)

    total = sum(digits)

    return total % 10 == 0

card = 4992739871642342341

is_valid = luhn_check(card)

print(f'Card number {card} is {"valid" if is_valid else "invalid"}')