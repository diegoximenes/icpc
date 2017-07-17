t = int(raw_input())
for _ in xrange(t):
    names = raw_input().split()
    names[-1] = "{}{}".format(names[-1][0].upper(),
                              "".join(names[-1][1:].lower()))
    for i in xrange(len(names) - 1):
        names[i] = "{}.".format(names[i][0].upper())
    print " ".join(names)
