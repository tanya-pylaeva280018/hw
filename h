import io
import numpy as np
import pickle

from operator import add

FILE = r"C:\Users\MSI Gaming\Desktop\векторcc.en.300.vec"

good = ['good', 'well', 'nice', 'pretty', 'fine', 'satisfactory', 'solid', 'fair', 'handsome', 'desirable']
bad = ['bad', 'poor', 'ill', 'amiss', 'evil', 'cheap', 'defective', 'inferior', 'low', 'mean']


def load_vectors(fname):
    fin = io.open(fname, 'r', encoding='utf-8', newline='\n', errors='ignore')
    # n, d = map(int, fin.readline().split())
    data = {}
    l_count = 0
    for line in fin:
        tokens = line.rstrip().split(' ')
        if tokens[0] in good or tokens[0] in bad:  # only words in lists
            data[tokens[0]] = map(float, np.array(tokens[1:]))
            l_count += 1
            # print(np.array(tokens[1:]))
    return data


d = load_vectors(FILE)

# print(d['nice'])  # слово - вектор

new_dict = {}
with open(r"C:\Users\MSI Gaming\Desktop\вектор\word2phones.pkl", "rb") as out_file:
    data = pickle.load(out_file)

# print(data['nice'])  # слово - транскрипция

for word in data.keys():
    try:
        new_dict[word] = (d[word], data[word])
    except:
        pass
        # print(word)

#print(new_dict.get('nice', None))

# with open("word2vectranscr.pkl", "wb") as out_file:
#   pickle.dump(new_dict, out_file, protocol=pickle.HIGHEST_PROTOCOL)


array_of_good_vectors = []

for i in range(len(good)):
    array_of_good_vectors.append(list(d[good[i]]))

#print(np.sum(array_of_good_vectors))
# print(
#     np.array(list(d[good[0]])) + np.array(list(d[good[1]])) + np.array(list(d[good[2]])) +
#     np.array(list(d[good[3]])) + np.array(list(d[good[4]])) + np.array(list(d[good[5]])) +
#     np.array(list(d[good[6]])) + np.array(list(d[good[7]])) + np.array(list(d[good[8]])) + np.array(list(d[good[9]]))
#)
# Angular = ['angular', 'gnarled', 'gnarly', 'craggy', 'awkward', 'angled']
# Round = ['plump', 'bumpy', 'circular', 'round', 'rounded' ]
# Bad = ['bad', 'poor', 'ill', 'amiss', 'evil', 'cheap', 'defective', 'inferior', 'low', 'mean' ]
# Good = ['good', 'well', 'nice', 'pretty', 'fine', 'satisfactory', 'solid', 'fair', 'handsome', 'desirable']
# Cold = ['cold', 'chill', 'chilly', 'inclement', 'wintry', 'frozen', 'frosty']
# Hot = ['hot', 'ardent', 'passionate', 'violent', 'warm', 'cordial', 'thermal', 'fervent', 'heated']
# Complex = ['complex', 'complicated', 'sophisticated', 'compound', 'intricate', 'composite', 'elaborate', 'tricky']
# Simple = ['plain', 'simple', 'ordinary', 'elementary', 'common', 'straightforward', 'easy']
# Cowardly = ['cowardly', 'coward', 'dastardly', 'sneaky', 'sneaking']
# Brave = ['brave', 'gallant', 'courageous', 'valiant', 'redoubtable', 'bold']
# Dangerous = ['terrible', 'frightful', 'dreadful', 'awful', 'agonizing', 'fearful', 'formidable', 'horrible', 'desperate', 'tremendous']
# Secure = ['secure', 'sure', 'safety', 'permissible', 'foolproof', 'safe', 'wholesome']
# Dark = ['dark', 'black', 'murky', 'shadowy', 'gloomy', 'shady']
# Luminous = ['light', 'clear', 'bright', 'blond', 'blonde', 'fair', 'luminous', 'lucid']
# Difﬁcult = ['difﬁcult', 'hard', 'laborious', 'serious', 'severe', 'grave', 'oppressive', 'painful', 'heavy', 'weighty']
# Easy = [ 'easy', 'light', 'lucky', 'facile', 'slight', 'gentle', 'airy', 'ready', 'dolly' ]
# Evil = ['wicked', 'evil', 'vicious', 'malicious', 'spiteful', 'angry', 'ﬁerce', 'severe', 'bad', 'mordant']
# Benign = ['beneﬁcent', 'good', 'benign', 'decent', 'gentle', 'gracious', 'kind' ]
# Faded = ['faded', 'withered', 'delicate', 'languid', 'bleak', 'ﬂat', 'faint', 'sickly' ]
# Bright = ['bright', 'vivid', 'shining', 'cheerful', 'striking', 'glowing', 'garish', 'colorful' ]
# Feeble = ['sickly', 'feeble', 'frail', 'weakly','puny', 'spindly' ]
# Strong = ['powerful', 'mighty', 'strong', 'vigorous', 'vibrant', 'powerfully', 'mightily', 'strongly']
# Masculine = ['feminine', 'womanly', 'ladylike']
# Feminine = ['masculine', 'manly', 'virile', 'masculine', 'manly']
# Passive = ['passive', 'dormant', 'quiescent', 'ﬂoppy', 'unemotional', 'tame', 'effortless', 'ﬂaccid']
# Active = ['active', 'dynamic', 'stirring', 'energetic', 'dynamical', 'favourable', 'ambitious', 'busy', 'industrious']
# Quiet = ['quiet', 'calm', 'soft', 'low', 'gentle', 'ﬂat']
# Loud = ['loud', 'noisy', 'notorious', 'pompous']
# Rough = ['rude', 'rough', 'gross', 'coarse', 'crude', 'tough', 'brute', 'barbaric', 'barbarous', 'beastly']
# Tender = ['tender', 'affectionate', 'gentle', 'delicate', 'soft', 'sweet', 'subtle', 'fond', 'sentimental', 'affectionate']
# Sad = ['sad', 'sorrowful', 'dreary', 'deplorable', 'elegiac', 'lamentable', 'melancholy', 'sorry']
# Joyful = ['merry', 'gay', 'cheerful', 'airy', 'glad', 'jolly', 'joyful', 'jaunty']
# Short = ['short', 'brief', 'small', 'little', 'skimpy']
# Long = ['long', 'tall', 'gaunt', 'spindly', 'lanky', 'voluminous', 'lengthy']
# Slow = ['slow', 'long', 'slack', 'sluggish', 'laggard', 'creeping',' leisurely', 'plodding']
# Quick = ['quick', 'fast', 'swift', 'agile', 'prompt', 'speedy', 'rapid', 'ready', 'brief']
# Small = ['small', 'little', 'petite', 'diminutive', 'short', 'triﬂing', 'petty']
# Big = ['large', 'great', 'big', 'greater', 'high', 'wide', 'major', 'grownup', 'hulk']
# Smooth = ['smooth', 'plain', 'even', 'glib', 'sleek', 'slick', 'polished', 'clean', 'ﬂuent']
# Rough_or_not_smooth = ['rough', 'uneven', 'rugged', 'coarse', 'corny', 'grainy', 'harsh', 'ragged', 'shaggy']
# Ugly = ['homely', 'ugly', 'mean', 'plain','charmless']
# Beautiful = ['beautiful', 'handsome', 'ﬁne', 'gallant', 'goodly', 'likely', 'lovely', 'personable', 'sheen']
synonyms = [['angular', 'gnarled', 'gnarly', 'craggy', 'awkward', 'angled'],
            ['plump', 'bumpy', 'circular', 'round', 'rounded' ],
            ['bad', 'poor', 'ill', 'amiss', 'evil', 'cheap', 'defective', 'inferior', 'low', 'mean' ],
            ['good', 'well', 'nice', 'pretty', 'fine', 'satisfactory', 'solid', 'fair', 'handsome', 'desirable'],
            ['cold', 'chill', 'chilly', 'inclement', 'wintry', 'frozen', 'frosty'],
            ['hot', 'ardent', 'passionate', 'violent', 'warm', 'cordial', 'thermal', 'fervent', 'heated'],
            ['complex', 'complicated', 'sophisticated', 'compound', 'intricate', 'composite', 'elaborate', 'tricky'],
            ['plain', 'simple', 'ordinary', 'elementary', 'common', 'straightforward', 'easy'],
            ['cowardly', 'coward', 'dastardly', 'sneaky', 'sneaking'],
            ['brave', 'gallant', 'courageous', 'valiant', 'redoubtable', 'bold'],
            ['terrible', 'frightful', 'dreadful', 'awful', 'agonizing', 'fearful', 'formidable', 'horrible', 'desperate', 'tremendous'],
            ['secure', 'sure', 'safety', 'permissible', 'foolproof', 'safe', 'wholesome'],
            ['dark', 'black', 'murky', 'shadowy', 'gloomy', 'shady'],
            ['light', 'clear', 'bright', 'blond', 'blonde', 'fair', 'luminous', 'lucid'],
            ['difﬁcult', 'hard', 'laborious', 'serious', 'severe', 'grave', 'oppressive', 'painful', 'heavy', 'weighty'],
            [ 'easy', 'light', 'lucky', 'facile', 'slight', 'gentle', 'airy', 'ready', 'dolly' ],
            ['wicked', 'evil', 'vicious', 'malicious', 'spiteful', 'angry', 'ﬁerce', 'severe', 'bad', 'mordant'],
            ['beneﬁcent', 'good', 'benign', 'decent', 'gentle', 'gracious', 'kind' ],
            ['faded', 'withered', 'delicate', 'languid', 'bleak', 'ﬂat', 'faint', 'sickly' ],
            ['bright', 'vivid', 'shining', 'cheerful', 'striking', 'glowing', 'garish', 'colorful' ],
            ['sickly', 'feeble', 'frail', 'weakly','puny', 'spindly' ],
            ['powerful', 'mighty', 'strong', 'vigorous', 'vibrant', 'powerfully', 'mightily', 'strongly'],
            ['feminine', 'womanly', 'ladylike'],
            ['masculine', 'manly', 'virile', 'masculine', 'manly'],
            ['passive', 'dormant', 'quiescent', 'ﬂoppy', 'unemotional', 'tame', 'effortless', 'ﬂaccid'],
            ['active', 'dynamic', 'stirring', 'energetic', 'dynamical', 'favourable', 'ambitious', 'busy', 'industrious'],
            ['quiet', 'calm', 'soft', 'low', 'gentle', 'ﬂat'],
            ['loud', 'noisy', 'notorious', 'pompous'],
            ['rude', 'rough', 'gross', 'coarse', 'crude', 'tough', 'brute', 'barbaric', 'barbarous', 'beastly'],
            ['tender', 'affectionate', 'gentle', 'delicate', 'soft', 'sweet', 'subtle', 'fond', 'sentimental', 'affectionate'],
            ['sad', 'sorrowful', 'dreary', 'deplorable', 'elegiac', 'lamentable', 'melancholy', 'sorry'],
            ['merry', 'gay', 'cheerful', 'airy', 'glad', 'jolly', 'joyful', 'jaunty'],
            ['short', 'brief', 'small', 'little', 'skimpy'],
            ['long', 'tall', 'gaunt', 'spindly', 'lanky', 'voluminous', 'lengthy'],
            ['slow', 'long', 'slack', 'sluggish', 'laggard', 'creeping',' leisurely', 'plodding'],
            ['quick', 'fast', 'swift', 'agile', 'prompt', 'speedy', 'rapid', 'ready', 'brief'],
            ['small', 'little', 'petite', 'diminutive', 'short', 'triﬂing', 'petty'],
            ['large', 'great', 'big', 'greater', 'high', 'wide', 'major', 'grownup', 'hulk'],
            ['smooth', 'plain', 'even', 'glib', 'sleek', 'slick', 'polished', 'clean', 'ﬂuent'],
            ['rough', 'uneven', 'rugged', 'coarse', 'corny', 'grainy', 'harsh', 'ragged', 'shaggy'],
            ['homely', 'ugly', 'mean', 'plain','charmless'],
            ['beautiful', 'handsome', 'ﬁne', 'gallant', 'goodly', 'likely', 'lovely', 'personable', 'sheen']]
for synonym in synonyms:
    sum = np.sum(synonym, axis=0)
    print(sum)
