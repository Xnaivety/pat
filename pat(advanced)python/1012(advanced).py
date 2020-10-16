if __name__ == '__main__':
	line1 = input().split(' ')
	num_person = int(line1[0])
	num_search = int(line1[1])
	class person: 
		def __init__(self,person_id,C_score,M_score,E_score):
			self.person_id = person_id
			self.C_score = C_score
			self.M_score = M_score
			self.E_score = E_score
			self.A_score = (C_score + M_score + E_score)/3
		def rank(self,personslist):
			pass

			
	
	persons = []
	for i in range(num_person):
		line = input().split(' ')
		persons.append(person(line[0],int(line[1]),int(line[2]),int(line[3])))
	
	ranklist = [x for x in range(1,num_person+1)]
	C_score_rank = sorted([i.C_score for i in persons],key = lambda x:x,reverse = True)
	C_score_rank_dict = {}
	for k in range(num_person):
		if(k==0):
			C_score_rank_dict[C_score_rank[k]] = k+1
		elif(k!=0):
			if(C_score_rank[k]==C_score_rank[k-1]):
				C_score_rank_dict[C_score_rank[k]] = C_score_rank_dict[C_score_rank[k-1]]
			else:
				C_score_rank_dict[C_score_rank[k]] = k+1

	M_score_rank = sorted([i.M_score for i in persons],key = lambda x:x,reverse = True)
	M_score_rank_dict = {}
	for k in range(num_person):
		if(k==0):
			M_score_rank_dict[M_score_rank[k]] = k+1
		elif(k!=0):
			if(M_score_rank[k]==M_score_rank[k-1]):
				M_score_rank_dict[M_score_rank[k]] = M_score_rank_dict[M_score_rank[k-1]]
			else:
				M_score_rank_dict[M_score_rank[k]] = k+1

	E_score_rank = sorted([i.E_score for i in persons],key = lambda x:x,reverse = True)
	E_score_rank_dict = {}
	for k in range(num_person):
		if(k==0):
			E_score_rank_dict[E_score_rank[k]] = k+1
		elif(k!=0):
			if(E_score_rank[k]==E_score_rank[k-1]):
				E_score_rank_dict[E_score_rank[k]] = E_score_rank_dict[E_score_rank[k-1]]
			else:
				E_score_rank_dict[E_score_rank[k]] = k+1
	A_score_rank = sorted([i.A_score for i in persons],key = lambda x:x,reverse = True)
	A_score_rank_dict = {}
	for k in range(num_person):
		if(k==0):
			A_score_rank_dict[A_score_rank[k]] = k+1
		elif(k!=0):
			if(A_score_rank[k]==A_score_rank[k-1]):
				A_score_rank_dict[A_score_rank[k]] = A_score_rank_dict[A_score_rank[k-1]]
			else:
				A_score_rank_dict[A_score_rank[k]] = k+1

	for j in range(num_search):
		index = input()
		have_person = 0
		for i in persons:
			if(i.person_id==index):
				have_person=1
				index_person = i
				break
		if(have_person==1):
			index_dict = {'A':A_score_rank_dict[index_person.A_score],'C':C_score_rank_dict[index_person.C_score],'M':M_score_rank_dict[index_person.M_score],'E':E_score_rank_dict[index_person.E_score]}
			index1 = sorted(index_dict.items(),key = lambda x:x[1],reverse = False)
			print(index1[0][1],end = ' ')
			print(index1[0][0])
		elif(have_person==0):
			print('N/A')

