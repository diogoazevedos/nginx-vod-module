import os

# get language codes
codes = set([])
for curLine in file(os.path.join(os.path.split(__file__)[0], '../vod/languages_x.h')):
	if not curLine.startswith('LANG('):
		continue
	splitted = curLine.split(',')
	codes.add(splitted[3].split('"')[1])
	if splitted[2].strip() != 'NULL':
		codes.add(splitted[2].split('"')[1])

# get hash size per starting letter
sizes = []
for letter in xrange(26):
	curCodes = filter(lambda x: x.startswith(chr(ord('a') + letter)), codes)
	langIntCodes = map(lambda x: ((ord(x[0]) - 96) << 10) | ((ord(x[1]) - 96) << 5) | (ord(x[2]) - 96), curCodes)

	hashSize = len(langIntCodes)
	while True:
		if len(langIntCodes) == len(set(map(lambda x: x % hashSize, langIntCodes))):
			break
		hashSize += 1

	sizes.append(hashSize)

# print the result
print '// generated by languages_hash_size.py\n'
print '#define ISO639_3_HASH_TOTAL_SIZE (%s)\n' % sum(sizes)
print 'static const language_hash_offsets_t iso639_3_hash_offsets[] = {'
pos = 0
for size in sizes:
	print '\t{ %s, %s },' % (pos, size)
	pos += size
print '};'
