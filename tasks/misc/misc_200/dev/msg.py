class Msg:

	SERVER_BANNER = '''
 #####  ######                                                                               
#     # #     #     ####  #       ####  #####    #    #   ##    ####  #    # # #    # ###### 
#     # #     #    #      #      #    #   #      ##  ##  #  #  #    # #    # # ##   # #      
#     # ######      ####  #      #    #   #      # ## # #    # #      ###### # # #  # #####  
#   # # #   #           # #      #    #   #      #    # ###### #      #    # # #  # # #      
#    #  #    #     #    # #      #    #   #      #    # #    # #    # #    # # #   ## #      
 #### # #     #     ####  ######  ####    #      #    # #    #  ####  #    # # #    # ###### 
'''
	SERVER_RULES  = '1. The server sends you a qr-code and you have 5 seconds to solve it\n'
	SERVER_RULES += '2. After solving a lot of qr-codes, we will reward you\n'

	SESSION_START = 'Do you want to start a captcha solution session? (Y/N): '

	EXIT = 'Close connection...\n'

	SERVER_AWARD  = 'Thank you for your help. This is a your award: '
	SERVER_AWARD += 'CupCTF{d85ae8bb45a49ab0eb529415241697f56e27db4f57ebe75808a8fa584985e44a}\n'
	ANSWER_MSG    = '\nAnswer: '
	SERVER_ANSWER_TIMEOUT = 'Time to solve is out!\n'
	CORRECT_QR = '[+] Correct!\n'
	INCORRECT_QR = "[-] Incorrect!\n"