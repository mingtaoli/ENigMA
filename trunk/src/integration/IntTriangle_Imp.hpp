// *****************************************************************************
// <ProjectName> ENigMA </ProjectName>
// <Description> Extended Numerical Multiphysics Analysis </Description>
// <HeadURL> $HeadURL$ </HeadURL>
// <LastChangedDate> $LastChangedDate$ </LastChangedDate>
// <LastChangedRevision> $LastChangedRevision$ </LastChangedRevision>
// <Author> Billy Araujo </Author>
// *****************************************************************************

namespace ENigMA
{

    namespace integration
    {

        template <typename Real>
        CIntTriangle<Real>::CIntTriangle()
        {
        }

        template <typename Real>
        CIntTriangle<Real>::~CIntTriangle()
        {
        }

        template <typename Real>
        void CIntTriangle<Real>::setGaussPoints()
        {

            // TODO:
        }

        template <typename Real>
        void CIntTriangle<Real>::setBarycentricGaussPoints()
        {

            // http://anhngq.wordpress.com/2010/02/19/numerical-quadrature-over-triangles/

            m_beta1.clear();
            m_beta2.clear();
            m_beta3.clear();
            m_wbeta.clear();

            switch (CIntGaussIntegration<Real>::m_integPoints)
            {
            case 1:
            {
                const Real o1beta1[1] = { 3.33333333333333e-001 };
                const Real o1beta2[1] = { 3.33333333333333e-001 };
                const Real o1beta3[1] = { 3.33333333333333e-001 };
                const Real o1wbeta[1] = { 1.0 };

                for (Integer k = 0; k < CIntGaussIntegration<Real>::m_integPoints; ++k)
                {
                    m_beta1.push_back(o1beta1[k]);
                    m_beta2.push_back(o1beta2[k]);
                    m_beta3.push_back(o1beta3[k]);
                    m_wbeta.push_back(o1wbeta[k]);
                }
            }
            break;

            case 3:
            {

                const Real o3beta1[3] = { 0.5, 0.0, 0.5 };
                const Real o3beta2[3] = { 0.0, 0.5, 0.5 };
                const Real o3beta3[3] = { 0.5, 0.5, 0.0 };
                const Real o3wbeta[3] = { 1.0, 1.0, 1.0 };

                for (Integer k = 0; k < CIntGaussIntegration<Real>::m_integPoints; ++k)
                {
                    m_beta1.push_back(o3beta1[k]);
                    m_beta2.push_back(o3beta2[k]);
                    m_beta3.push_back(o3beta3[k]);
                    m_wbeta.push_back(o3wbeta[k]);
                }
            }

            break;

            case 6:
            {

                const Real o6beta1[6] = { 9.15762135097700e-002, 9.15762135097701e-002, 8.16847572980458e-001, 4.45948490915965e-001, 4.45948490915965e-001, 1.08103018168070e-001 };
                const Real o6beta2[6] = { 9.15762135097710e-002, 8.16847572980459e-001, 9.15762135097710e-002, 4.45948490915965e-001, 1.08103018168070e-001, 4.45948490915965e-001 };
                const Real o6beta3[6] = { 8.16847572980459e-001, 9.15762135097710e-002, 9.15762135097710e-002, 1.08103018168070e-001, 4.45948490915965e-001, 4.45948490915965e-001 };
                const Real o6wbeta[6] = { 5.49758718276610e-002, 5.49758718276610e-002, 5.49758718276610e-002, 1.11690794839000e-001, 1.11690794839000e-001, 1.11690794839000e-001 };

                for (Integer k = 0; k < CIntGaussIntegration<Real>::m_integPoints; ++k)
                {
                    m_beta1.push_back(o6beta1[k]);
                    m_beta2.push_back(o6beta2[k]);
                    m_beta3.push_back(o6beta3[k]);
                    m_wbeta.push_back(o6wbeta[k]);
                }
            }

            break;

            case 7:
            {
                const Real o7beta1[7] = { 3.33333333333333e-001, 1.01286507323457e-001, 1.01286507323457e-001, 7.97426985353088e-001, 4.70142064105115e-001, 4.70142064105115e-001, 5.97158717897699e-002 };
                const Real o7beta2[7] = { 3.33333333333333e-001, 1.01286507323456e-001, 7.97426985353087e-001, 1.01286507323456e-001, 5.97158717897700e-002, 4.70142064105115e-001, 4.70142064105115e-001 };
                const Real o7beta3[7] = { 3.33333333333333e-001, 7.97426985353087e-001, 1.01286507323456e-001, 1.01286507323456e-001, 4.70142064105115e-001, 5.97158717897700e-002, 4.70142064105115e-001 };
                const Real o7wbeta[7] = { 1.12515000150000e-001, 6.29695902724135e-002, 6.29695902724135e-002, 6.29695902724135e-002, 6.61970763942530e-002, 6.61970763942530e-002, 6.61970763942530e-002 };

                for (Integer k = 0; k < CIntGaussIntegration<Real>::m_integPoints; ++k)
                {
                    m_beta1.push_back(o7beta1[k]);
                    m_beta2.push_back(o7beta2[k]);
                    m_beta3.push_back(o7beta3[k]);
                    m_wbeta.push_back(o7wbeta[k]);
                }
            }

            break;

            case 12:
            {

                const Real o12beta1[12] = { 6.30890144915020e-002, 6.30890144915021e-002, 8.73821971016996e-001, 2.49286745170911e-001, 2.49286745170911e-001, 5.01426509658180e-001, 5.31450498448160e-002, 5.31450498448161e-002, 3.10352451033785e-001, 6.36502499121399e-001, 6.36502499121399e-001, 3.10352451033785e-001 };
                const Real o12beta2[12] = { 6.30890144915020e-002, 8.73821971016996e-001, 6.30890144915020e-002, 2.49286745170910e-001, 5.01426509658179e-001, 2.49286745170910e-001, 3.10352451033785e-001, 6.36502499121399e-001, 5.31450498448160e-002, 5.31450498448160e-002, 3.10352451033785e-001, 6.36502499121399e-001 };
                const Real o12beta3[12] = { 8.73821971016996e-001, 6.30890144915020e-002, 6.30890144915020e-002, 5.01426509658179e-001, 2.49286745170910e-001, 2.49286745170910e-001, 6.36502499121399e-001, 3.10352451033785e-001, 6.36502499121399e-001, 3.10352451033785e-001, 5.31450498448160e-002, 5.31450498448160e-002 };
                const Real o12wbeta[12] = { 2.54224531851035e-002, 2.54224531851035e-002, 2.54224531851035e-002, 5.83931378631895e-002, 5.83931378631895e-002, 5.83931378631895e-002, 4.14255378091870e-002, 4.14255378091870e-002, 4.14255378091870e-002, 4.14255378091870e-002, 4.14255378091870e-002, 4.14255378091870e-002 };

                for (Integer k = 0; k < CIntGaussIntegration<Real>::m_integPoints; ++k)
                {
                    m_beta1.push_back(o12beta1[k]);
                    m_beta2.push_back(o12beta2[k]);
                    m_beta3.push_back(o12beta3[k]);
                    m_wbeta.push_back(o12wbeta[k]);
                }
            }

            break;

            case 16:

            {
                const Real o16beta1[16] = { 3.33333333333333e-001, 4.59292588292723e-001, 4.59292588292723e-001, 8.14148234145540e-002, 1.70569307751760e-001, 1.70569307751760e-001, 6.58861384496480e-001, 5.05472283170310e-002, 5.05472283170311e-002, 8.98905543365938e-001, 2.63112829634638e-001, 2.63112829634638e-001, 7.28492392955404e-001, 7.28492392955404e-001, 8.39477740995798e-003, 8.39477740995798e-003 };
                const Real o16beta2[16] = { 3.33333333333333e-001, 4.59292588292723e-001, 8.14148234145540e-002, 4.59292588292723e-001, 1.70569307751760e-001, 6.58861384496480e-001, 1.70569307751760e-001, 5.05472283170310e-002, 8.98905543365938e-001, 5.05472283170310e-002, 7.28492392955404e-001, 8.39477740995800e-003, 8.39477740995800e-003, 2.63112829634638e-001, 7.28492392955404e-001, 2.63112829634638e-001 };
                const Real o16beta3[16] = { 3.33333333333333e-001, 8.14148234145540e-002, 4.59292588292723e-001, 4.59292588292723e-001, 6.58861384496480e-001, 1.70569307751760e-001, 1.70569307751760e-001, 8.98905543365938e-001, 5.05472283170310e-002, 5.05472283170310e-002, 8.39477740995800e-003, 7.28492392955404e-001, 2.63112829634638e-001, 8.39477740995800e-003, 2.63112829634638e-001, 7.28492392955404e-001 };
                const Real o16wbeta[16] = { 7.21578038388935e-002, 4.75458171336425e-002, 4.75458171336425e-002, 4.75458171336425e-002, 5.16086852673590e-002, 5.16086852673590e-002, 5.16086852673590e-002, 1.62292488115990e-002, 1.62292488115990e-002, 1.62292488115990e-002, 1.36151570872175e-002, 1.36151570872175e-002, 1.36151570872175e-002, 1.36151570872175e-002, 1.36151570872175e-002, 1.36151570872175e-002 };

                for (Integer k = 0; k < CIntGaussIntegration<Real>::m_integPoints; ++k)
                {
                    m_beta1.push_back(o16beta1[k]);
                    m_beta2.push_back(o16beta2[k]);
                    m_beta3.push_back(o16beta3[k]);
                    m_wbeta.push_back(o16wbeta[k]);
                }
            }

            break;

            case 17:

            {
                const Real o17beta1[17] = { 2.59016914636572e-001, 1.91577434497285e-001, 4.81440411116636e-001, 5.32050948690330e-001, 7.89180748710157e-001, 4.67041168284076e-002, 2.43294047349708e-001, 2.39834898348413e-001, 3.29253420983258e-002, 9.53028216453241e-001, 7.49069919469304e-001, 3.25934837676662e-002, 5.28127769606800e-001, 5.08572946885014e-002, 4.64670742502622e-001, 1.36209761693663e-001, 5.13193590322896e-002 };
                const Real o17beta2[17] = { 5.11740721100636e-001, 7.58910363747916e-001, 1.52964748176719e-001, 3.15139873507434e-002, 5.11786839328832e-002, 1.96451682410697e-002, 2.34749045972567e-001, 4.90868257718777e-002, 4.38223753732188e-001, 3.30021067703340e-002, 2.08875861463606e-001, 9.20892924665470e-001, 2.74274095467480e-001, 1.65458517909747e-001, 4.93001169983355e-001, 4.08080496784694e-001, 7.12787216274182e-001 };
                const Real o17beta3[17] = { 2.29242364262792e-001, 4.95122017547988e-002, 3.65594840706645e-001, 4.36435063958927e-001, 1.59640567356960e-001, 9.33650714930523e-001, 5.21956906677725e-001, 7.11078275879710e-001, 5.28850904169486e-001, 1.39696767764251e-002, 4.20542190670900e-002, 4.65135915668635e-002, 1.97598134925720e-001, 7.83684187401751e-001, 4.23280875140226e-002, 4.55709741521642e-001, 2.35893424693528e-001 };
                const Real o17wbeta[17] = { 5.95659566285715e-002, 2.81339023000646e-002, 3.50073547709683e-002, 2.43807745039326e-002, 2.84337444805101e-002, 7.82285663421878e-003, 5.17911134100478e-002, 3.13422953909681e-002, 2.45495158492514e-002, 5.37138255764711e-003, 2.57156551476807e-002, 1.04593334080251e-002, 4.93778084121232e-002, 2.82477236231758e-002, 3.21888168401566e-002, 2.52208924769323e-002, 3.23908735657260e-002 };

                for (Integer k = 0; k < CIntGaussIntegration<Real>::m_integPoints; ++k)
                {
                    m_beta1.push_back(o17beta1[k]);
                    m_beta2.push_back(o17beta2[k]);
                    m_beta3.push_back(o17beta3[k]);
                    m_wbeta.push_back(o17wbeta[k]);
                }
            }

            break;

            case 20:

            {
                const Real o20beta1[20] = { 4.96963686517477e-001, 3.27737279831677e-001, 4.59306059914741e-001, 1.80193738693445e-001, 7.42607139539477e-001, 4.54226607159181e-002, 4.93019828416712e-001, 3.38561489335711e-002, 2.22635403645525e-001, 2.26497889207337e-001, 2.52265246627187e-002, 7.45011886680378e-001, 3.37758387591633e-002, 4.50682411443534e-002, 1.31426222762174e-001, 4.22683133407192e-001, 3.56668844716040e-001, 9.11955121193499e-001, 6.16826389139707e-001, 1.72059456415730e-001 };
                const Real o20beta2[20] = { 4.78345124817644e-001, 3.37384423616899e-001, 1.24437846325473e-001, 6.36556972364812e-001, 3.89975936323789e-002, 9.09343714009646e-001, 1.96826603759659e-002, 2.19131112934771e-001, 3.83358856024087e-002, 7.38979506347510e-001, 4.80098928580052e-001, 2.17513716531818e-001, 7.40471682087998e-001, 4.41353150992668e-002, 4.43129214297882e-001, 4.44095359365284e-001, 1.43083140105137e-001, 4.39297015841188e-002, 1.97320936454502e-001, 1.97938105917001e-001 };
                const Real o20beta3[20] = { 2.46911886648786e-002, 3.34878296551425e-001, 4.16256093759786e-001, 1.83249288941743e-001, 2.18395266828144e-001, 4.52336252744363e-002, 4.87297511207323e-001, 7.47012738131658e-001, 7.39028710752066e-001, 3.45226044451528e-002, 4.94674546757229e-001, 3.74743967878046e-002, 2.25752479152839e-001, 9.10796443756380e-001, 4.25444562939944e-001, 1.33221507227524e-001, 5.00248015178823e-001, 4.41151772223827e-002, 1.85852674405791e-001, 6.30002437667269e-001 };
                const Real o20wbeta[20] = { 1.77691309112296e-002, 4.66754493690407e-002, 2.96528333143297e-002, 3.88044763499761e-002, 2.25151145701125e-002, 1.31416239463618e-002, 1.56034173661051e-002, 1.96706543468974e-002, 2.24796284950108e-002, 2.08710839496907e-002, 1.78766120070067e-002, 2.14769586560792e-002, 2.04099824730397e-002, 1.27034230053368e-002, 3.68871309935631e-002, 3.81319981153578e-002, 1.50864232581216e-002, 1.23842228769212e-002, 3.99507233699274e-002, 3.79091126258925e-002 };

                for (Integer k = 0; k < CIntGaussIntegration<Real>::m_integPoints; ++k)
                {
                    m_beta1.push_back(o20beta1[k]);
                    m_beta2.push_back(o20beta2[k]);
                    m_beta3.push_back(o20beta3[k]);
                    m_wbeta.push_back(o20wbeta[k]);
                }
            }

            break;
            }
        }
    }
}
