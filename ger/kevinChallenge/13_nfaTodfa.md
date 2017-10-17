Today I have another super computer-sciency algorithm. It gets the deterministic finite automata equivalent of a non deterministic one given its 'adjacency list representation':

```python
    class Automata:

        def __init__(self, Q=[], sigma=[], delta={}, q_0=None, F = []):
            self.Q = set(Q)
            self.sigma = set(sigma)
            self.delta = defaultdict(None, delta)
            self.q_0 = q_0
            self.F = set(F)
            

        def add_state(self, new_state):
            self.Q.add(new_state)
            self.delta[new_state] = defaultdict(set)
        
        def add_transition(self, from_state, with_value, to_state):
                self.delta[from_state][with_value].add(to_state)

        def dfa_transform(self):
            def p(s):
                result = [[]]
                for elem in s:
                    result.extend([x + [elem] for x in result])
                return result

            deterministic = {
                'Q':p(self.Q), 
                'sigma':self.sigma,
                'delta':None,
                'q_0':self.q_0,
                'F':None
            }

            # determinisic sigma
            delta = {} #from state in P(Q):list to set of states given a key
            # delta[from_tuple][key] = to_set

            for state_list in deterministic['Q'][1:]: 
                delta[tuple(state_list)] = {}

                for key in self.sigma:
                    to_set = set()

                    for ind_state in state_list:
                        to_set |= self.delta[ind_state][key]

                    delta[tuple(state_list)][key] = to_set
                

            deterministic['delta'] = delta

            # deterministic F
            F = []
            for state_list in deterministic['Q']: 
                for ac in self.F:
                    if ac in state_list:
                        F.append(state_list)
                        break
                    
            deterministic['F'] = F
            return deterministic
```